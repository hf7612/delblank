#include <sys/types.h>
       #include <sys/stat.h>
       #include <unistd.h>
 #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <fcntl.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fnmatch.h>
#include <grp.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <pwd.h>
#include <regex.h>
#include <sched.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <syslog.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#include <utime.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h> /*"readdir" etc. are defined here. */
#include <dirent.h> /*limits.h defines "PATH_MAX". */
#include <limits.h> /*List the files in "dir_name". */
#include <sys/types.h>
#include <dirent.h>
#include "look_long_link.h" // /home/user/t/delblank/look_long_link.h

#define DIRTREE_ABORTVAL ((struct dirtree *)1)
struct dirtree *dirtree_handle_callback(struct dirtree *new, int (*callback)(struct 
dirtree *node));
char *dirtree_path(struct dirtree *node, int *plen);// struct stat {

// };
struct num_cache *inodes;
struct dirtree {
  struct dirtree *next, *parent, *child;
  long extra; // place for user to store their stuff (can be pointer)
  struct stat st;
  char *symlink;
  int dirfd;
  char again;
  char name[];
};
char toybuf[4096], libbuf[4096];
int strstart(char **a, char *b)
{
  int len = strlen(b), i = !strncmp(*a, b, len);

  if (i) *a += len;

  return i;
}
// void perror_msg(char *msg, ...)
// {
//   va_list va;

//   va_start(va, msg);
//   verror_msg(msg, errno, va);
//   va_end(va);
// }
struct dirtree *dirtree_add_node(struct dirtree *parent, char *name, int flags) { struct dirtree *dt = NULL; struct stat st; int len = 0, linklen = 0;
  if (name) { // open code this because haven't got node to call dirtree_parentfd() on yet
    int fd = parent ? parent->dirfd : AT_FDCWD;
    if (fstatat(fd, name, &st, AT_SYMLINK_NOFOLLOW*!(flags&DIRTREE_SYMFOLLOW)))
      goto error;
    if (S_ISLNK(st.st_mode)) {
      if (0>(linklen = readlinkat(fd, name, libbuf, 4095))) goto error;
      libbuf[linklen++]=0; }
    len = strlen(name); }
  dt = xzalloc((len = sizeof(struct dirtree)+len+1)+linklen);
  dt->parent = parent;
  if (name) {
    memcpy(&(dt->st), &st, sizeof(struct stat));
    strcpy(dt->name, name);
    if (linklen) dt->symlink = memcpy(len+(char *)dt, libbuf, linklen); }
  return dt;
error:
  if (!(flags&DIRTREE_SHUTUP) && !isdotdot(name)) { char *path = parent ? dirtree_path(parent, 0) : "";
    perror_msg("%s%s%s", path, parent ? "/" : "", name);
    if (parent) free(path);
  }
  if (parent) parent->symlink = (char *)1;
  free(dt); return 0; }
char *dirtree_path(struct dirtree *node, int *plen) { char *path; int len;
  if (!node) {
    path = malloc(*plen); //xmalloc(*plen);
    *plen = 0;
    return path; }
  len = (plen ? *plen : 0)+strlen(node->name)+1;
  path = dirtree_path(node->parent, &len);
  if (len && path[len-1] != '/') path[len++]='/';
  len = (stpcpy(path+len, node->name) - path);
  if (plen) *plen = len;
  return path; }
int dirtree_recurse(struct dirtree *node, int (*callback)(struct dirtree *node), int dirfd, int flags) { struct dirtree *new, **ddt = &(node->child); struct dirent *entry; DIR *dir;
  node->dirfd = dirfd;
  if (node->dirfd == -1 || !(dir = fdopendir(node->dirfd))) {
    if (!(flags & DIRTREE_SHUTUP)) {
      char *path = dirtree_path(node, 0); printf("No %s", path); // perror_msg("No %s", path); 
      free(path); }
    close(node->dirfd);
    return flags; } // according to the fddir() man page, the filehandle in the DIR * can still // be externally used by things that don't lseek() it. // The extra parentheses are to shut the stupid compiler up.
  while ((entry = readdir(dir))) {
    if ((flags&DIRTREE_PROC) && !isdigit(*entry->d_name)) continue;
    if (!(new = dirtree_add_node(node, entry->d_name, flags))) continue;
    new = dirtree_handle_callback(new, callback);
    if (new == DIRTREE_ABORTVAL) break;
    if (new) {
      *ddt = new;
      ddt = &((*ddt)->next); } }
  if (flags & DIRTREE_COMEAGAIN) {
    node->again++;
    flags = callback(node); } // This closes filehandle as well, so note it
  closedir(dir);
  node->dirfd = -1;
  return flags; }
int readlinkat0(int dirfd, char *path, char *buf, int len) { if (!len) return 0; 
  len = readlinkat(dirfd, path, buf, len-1); if (len<1) return 0;
  buf[len] = 0; return len; } 
int dirtree_parentfd(struct dirtree *node) { return node->parent ? node->parent->dirfd : AT_FDCWD; } 
struct dirtree *dirtree_handle_callback(struct dirtree *new, int (*callback)(struct dirtree *node)) { int flags;
  if (!new) return DIRTREE_ABORTVAL;
  if (!callback) return new;
  flags = callback(new);
  if (S_ISDIR(new->st.st_mode) && (flags & (DIRTREE_RECURSE|DIRTREE_COMEAGAIN))){ //printf(" \n joes name:%s \n", new->name);//joes
    flags = dirtree_recurse(new, callback, openat(dirtree_parentfd(new), new->name, O_CLOEXEC), flags);}//else{ printf(" \n joes2 name:%s \n", new->name); }//joes // If this had children, it was callback's job to free them already.
  if (!(flags & DIRTREE_SAVE)) { free(new);
    new = NULL; }
  return (flags & DIRTREE_ABORT)==DIRTREE_ABORT ? DIRTREE_ABORTVAL : new; }
struct dirtree *dirtree_flagread(char *path, int flags, int (*callback)(struct dirtree *node)) {
  return dirtree_handle_callback(dirtree_add_node(0, path, flags), callback); } 
struct dirtree *dirtree_read(char *path, int (*callback)(struct dirtree *node)) {
  return dirtree_flagread(path, 0, callback); }
static int scan_pids(struct dirtree *node) { char *s = toybuf+256; struct dirent *entry; DIR *dp; int pid, dirfd; if (!node->parent) return DIRTREE_RECURSE;     if (!(pid = atol(node->name))) return 0; printf("\n joes pid:%d \n", pid);
  sprintf(toybuf, "/proc/%d/cmdline", pid); if (!(readfile(toybuf, toybuf, 256))) return 0;
  sprintf(s, "%d/fd", pid); if (-1==(dirfd = openat(dirtree_parentfd(node), s, O_RDONLY))) return 0;
  if (!(dp = fdopendir(dirfd))) { close(dirfd); return 0; }
  while ((entry = readdir(dp))) { s = toybuf+256; if (!readlinkat0(dirfd, entry->d_name, s, sizeof(toybuf)-256)) continue; // Can the "[0000]:" happen in a modern kernel?
    if (strstart(&s, "socket:[") || strstart(&s, "[0000]:")) { long long ll = atoll(s); sprintf(s, "%d/%s", pid, getbasename(toybuf)); 
    add_num_cache(&inodes, ll, s, strlen(s)+1);//add_num_cache(&TT.inodes, ll, s, strlen(s)+1);
     } }     closedir(dp); return 0; }
int main(int argc, char **argv)
{
    char path[1024]="/proc/";
    char *pid = argv[1];
    dirtree_read("/proc", scan_pids);
    sprintf(path, "/proc/%d", atoi(pid));
    printf(" path:%s ", path);
    DIR *d = opendir(path);
}
