#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h> /*"readdir" etc. are defined here. */
#include <dirent.h> /*limits.h defines "PATH_MAX". */
#include <limits.h> /*List the files in "dir_name". */
#include <sys/types.h>
#include <dirent.h>
// static void list_dir (const char *dir_name) { DIR *d;     /*Open the directory specified by "dir_name". */
//     d = opendir (dir_name);     /*Check it was opened. */
//     if (! d) { fprintf (stderr, "Cannot open directory '%s': %s\n", dir_name, strerror (errno)); exit (EXIT_FAILURE); }
//     while (1) { struct dirent *entry; const char *d_name;         /*"Readdir" gets subsequent entries from "d". */
//         entry = readdir (d);
//         if (! entry) {             /*There are no more entries in this directory, so break                out of the while loop. */
//             break; }
//         d_name = entry->d_name;         /*Print the name of the file and directory. */
// 	printf ("%s/%s\n", dir_name, d_name);
// #if 0  /*If you don't want to print the directories, use the 	   following line: */
//         if (! (entry->d_type & DT_DIR)) { printf ("%s/%s\n", dir_name, d_name); }
// #endif /*0 */
//         if (entry->d_type & DT_DIR) {             /*Check that the directory is not "d" or d's parent. */
//             if (strcmp (d_name, "..") != 0 && strcmp (d_name, ".") != 0) { int path_length; char path[PATH_MAX];
//                 path_length = snprintf (path, PATH_MAX, "%s/%s", dir_name, d_name);
//                 printf ("%s\n", path);
//                 if (path_length >= PATH_MAX) { fprintf (stderr, "Path length has got too long.\n");
//                     exit (EXIT_FAILURE); }                 /*Recursively call "li st_dir" with the new path. */
//                 list_dir (path); } } }     /*After going through all the entries, close the directory. */
//     if (closedir (d)) { fprintf (stderr, "Could not close '%s': %s\n", dir_name, strerror (errno)); exit (EXIT_FAILURE); } }
// __dirstream r;
#define MAX_CONNECT 4096*100
int tcpStat[MAX_CONNECT];
static void list_dir2 (const char *dir_name) { DIR *d;     /*Open the directory specified by "dir_name". */
    printf(" \n\n map:\n\n");
    d = opendir (dir_name); 
    int found = 0;
    if (d) {
        char link[256]; int r=0;
        int dirfd0 = dirfd(d); 
        int nCmp = strlen("socket:[");
        struct dirent *entry = readdir (d);
        while (entry) {
            const char *d_name = entry->d_name; // printf(" na:%s len:%d %d \n", d_name, entry->d_reclen, strlen(d_name)); 
            if (d_name[0] != '.' && d_name[1] != '.'){  //printf ("%s/%s\n", dir_name, d_name);       /*Print the name of the file and directory. */ 
                link[0] = 0; 
                r=readlinkat(dirfd0, d_name, link, 256);
                if( r > 0 && r< 256 ){
                    link[r] = 0;
                    if(!strncmp("socket:[", link, nCmp)) { 
                        int ino = atoi(link+nCmp);
                        printf(" linkggg:%s len:%d ino:%d ", link, entry->d_reclen, ino); 
                        for(int i=0;i<MAX_CONNECT; i++){
                            if(tcpStat[i]){
                                printf(" %d ", tcpStat[i]);
                                if(tcpStat[i] == ino){
                                    printf("\n found:%d \n", tcpStat[i]);
                                    found=1;
                                    break; }
                            } else
                                break; 
                        } } }; }
            if(found)break;
            entry = readdir (d); }
        closedir(d);
    }else{
        fprintf (stderr, "Cannot open directory '%s': %s\n", dir_name, strerror (errno)); exit (EXIT_FAILURE); } 
    // printf("\n uuuuuuuuuu \n");
}
int main (int argc, char *argv[]) {
    FILE *pF = fopen("/proc/net/tcp", "rb");
    char buf[4096] = {0};
    if(pF){
        if(!fgets(buf, sizeof(buf), pF)) return 0; //skip header.
        memset(buf+34, 0, 3);
        int i = 0;
        while (i<MAX_CONNECT && fgets(buf, sizeof(buf), pF)) { //printf(" jjjj0:%s ooo:%s ", buf, buf+34);
            if(!strncmp(buf+34, "01 ", 3)){ // printf(" jjjj:%s node:\n%d ", buf, atoi(buf+91));
                tcpStat[i++] = atoi(buf+91);
            } }
        fclose(pF);}
    // int i = 0;
    // printf(" list:\n\n");
    // for(i=0;i<MAX_CONNECT; i++){
    //     if(tcpStat[i])
    //         printf(" %d ", tcpStat[i]);
    //     else
    //         break; 
    // }
    // list_dir ("/proc");///usr/share/games");
    if(argc == 2){ //printf(" \n dddddddddddd:%s \n", argv[1]);
        sprintf(buf, "/proc/%s/fd", argv[1]);
        list_dir2 (buf);// "/proc/30514/fd");///usr/share/games");
    }else {
        list_dir2 ("/proc/22990/fd");}
    return 0; }