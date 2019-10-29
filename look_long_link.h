#ifndef look_long_link 
#define look_long_link
 

struct ptr_len {
  void *ptr;
  long len;
};

struct str_len {
  char *str;
  long len;
};

// llist.c

// All these list types can be handled by the same code because first element
// is always next pointer, so next = (mytype *)&struct. (The payloads are
// named differently to catch using the wrong type early.)

struct string_list {
  struct string_list *next;
  char str[0];
};

struct arg_list {
  struct arg_list *next;
  char *arg;
};

struct double_list {
  struct double_list *next, *prev;
  char *data;
};

struct num_cache {
  struct num_cache *next;
  long long num;
  char data[];
};

// void llist_free_arg(void *node);
// void llist_free_double(void *node);
// void llist_traverse(void *list, void (*using)(void *node));
// void *llist_pop(void *list);  // actually void **list
// void *dlist_pop(void *list);  // actually struct double_list **list
// void dlist_add_nomalloc(struct double_list **list, struct double_list *new);
// struct double_list *dlist_add(struct double_list **list, char *data);
// void *dlist_terminate(void *list);
// struct num_cache *get_num_cache(struct num_cache *cache, long long num);
// struct num_cache *add_num_cache(struct num_cache **cache, long long num, void *data, int len);  // args.c
// void get_optflags(void);

// dirtree.c

// Values returnable from callback function (bitfield, or them together)
// Default with no callback is 0

// Add this node to the tree
#define DIRTREE_SAVE         1
// Recurse into children
#define DIRTREE_RECURSE      2
// Call again after handling all children of this directory
// (Ignored for non-directories, sets linklen = -1 before second call.)
#define DIRTREE_COMEAGAIN    4
// Follow symlinks to directories
#define DIRTREE_SYMFOLLOW    8
// Don't warn about failure to stat
#define DIRTREE_SHUTUP      16
// Breadth first traversal, conserves filehandles at the expense of memory
#define DIRTREE_BREADTH     32
// skip non-numeric entries
#define DIRTREE_PROC        64
// Don't look at any more files in this directory.
#define DIRTREE_ABORT      256

#define DIRTREE_ABORTVAL ((struct dirtree *)1)

// struct dirtree {
//   struct dirtree *next, *parent, *child;
//   long extra; // place for user to store their stuff (can be pointer)
//   struct stat st;
//   char *symlink;
//   int dirfd;
//   char again;
//   char name[];
// };

// int isdotdot(char *name);
// struct dirtree *dirtree_add_node(struct dirtree *p, char *name, int flags);
// char *dirtree_path(struct dirtree *node, int *plen);
// int dirtree_notdotdot(struct dirtree *catch);
// int dirtree_parentfd(struct dirtree *node);
// int dirtree_recurse(struct dirtree *node, int (*callback)(struct dirtree *node),
//   int dirfd, int symfollow);
// struct dirtree *dirtree_flagread(char *path, int flags,
//   int (*callback)(struct dirtree *node));
// struct dirtree *dirtree_read(char *path, int (*callback)(struct dirtree *node));

// help.c 
#endif