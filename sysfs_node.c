/*   FUSE: Filesystem in Userspace   Copyright (C) 2001-2008  Miklos Szeredi <miklos@szeredi.hu>   This program can be distributed under the terms of the GNU GPL.   See the file COPYING. */
// #include "fuse_i.h" #include <linux/pagemap.h> #include <linux/slab.h> #include <linux/file.h> #include <linux/seq_file.h> #include <linux/init.h> 
#include <linux/module.h> 
#include <linux/fs.h> 
#include <linux/slab.h>
 #include <linux/delay.h> 
#include <linux/kobject.h>
 # define SLAB_ACCOUNT		0x04000000UL
struct fuse_inode { // struct inode inode;
	int a;
	int b;
};
// struct inode {
// 	int			i_mode;
// 	unsigned short		i_opflags;
// };
static void fuse_sysfs_cleanup(void) {
	// sysfs_remove_mount_point(fuse_kobj,"connections");
	// kobject_put(fuse_kobj); 
}
static int num;
static struct kmem_cache *fuse_inode_cachep;
static void fuse_inode_init_once(void *foo) { // struct inode *inode = foo; // inode_init_once(inode); 
	printk(" joes5 5 slab_ctor is called! object %d has been inited!\n", num);
    num++;
	}
static bool cont_test=1; module_param(cont_test, bool, 0644);
struct slab_test{
    int val;
};
struct slab_test *object1 = NULL, *object2 = NULL; 

static int foo; /*  * The "foo" file where a static variable is read from and written to.  */
static ssize_t foo_show(struct kobject *kobj, struct kobj_attribute *attr,     char *buf) { return sprintf(buf, "%d\n", foo); }
static ssize_t foo_store(struct kobject *kobj, struct kobj_attribute *attr,       const char *buf, size_t count) { 
	printk(" buf:%s \n", buf);
	return count; }
static struct kobj_attribute foo_attribute = __ATTR(i2c_unlock, 0666, foo_show, foo_store); /*  * Create a group of attributes so that we can create and destroy them all  * at once.  */
static struct attribute *attrs[] = { &foo_attribute.attr,       NULL,  /* need to NULL terminate the list of attributes */ }; /*  * An unnamed attribute group will put all of the attributes directly in  * the kobject directory.  If we specify a name, a subdirectory will be  * created for the attributes with the directory being the name of the  * attribute group.  */
static struct attribute_group attr_group = { .attrs = attrs, };
static struct kobject *example_kobj;
static int example_init2(void) { int retval;//static int __init example_init(void) { int retval;
     example_kobj = kobject_create_and_add("i2c_recovery2", kernel_kobj); if (!example_kobj) return -ENOMEM;      /* Create the files associated with this kobject */
     retval = sysfs_create_group(example_kobj, &attr_group); if (retval) kobject_put(example_kobj);
     return retval; }
// sysfs_remove_group(&pdev->dev.kobj,&gpio_keys_attr_group);
static void example_exit2(void) { sysfs_remove_group(example_kobj,&attr_group); kobject_put(example_kobj); }// static void __exit example_exit(void) { sysfs_remove_group(&pdev->dev.kobj,&attr_group); kobject_put(example_kobj); }
// module_init(example_init); module_exit(example_exit); MODULE_LICENSE("GPL"); MODULE_AUTHOR("Wupeng");

static int __init fuse_init(void) {  struct inode *inode;// struct fuse_inode *fi; // 
	//  int res; printk(KERN_INFO "fuse init (API version %i.%i)\n",FUSE_KERNEL_VERSION,FUSE_KERNEL_MINOR_VERSION); INIT_LIST_HEAD(&fuse_conn_list); res = fuse_fs_init(); if (res) goto err;
	// res = fuse_dev_init(); if (res) goto err_fs_cleanup; res = fuse_sysfs_init(); if (res) goto err_dev_cleanup; res = fuse_ctl_init(); if (res) goto err_sysfs_cleanup;
	// sanitize_global_limit(&max_user_bgreq); sanitize_global_limit(&max_user_congthresh);
	// return 0; err_sysfs_cleanup: fuse_sysfs_cleanup(); err_dev_cleanup: fuse_dev_cleanup(); err_fs_cleanup: fuse_fs_cleanup(); err: return res; 
	printk(" joes5 5 aa1 \n");
	example_init2(); 
	// fuse_inode_cachep = kmem_cache_create("joes_fuse_inode_joes5",1024,0,SLAB_HWCACHE_ALIGN|SLAB_ACCOUNT,fuse_inode_init_once);
	// printk(" joes5 5 fuse_inode_cachep2:%p ", fuse_inode_cachep); // // if(cont_test) // // 	inode = km em_cache_alloc(fuse_inode_cachep,GFP_KERNEL); //if (!inode) return NULL;
	// while(cont_test){
	// 	printk(" joes5 5 cache allo ");
	// 	kmem_cache_alloc(fuse_inode_cachep,GFP_KERNEL); //if (!inode) return NULL;
	// 	msleep(1);
	// }	
	return 0;
}
static void __exit fuse_exit(void) { printk(KERN_DEBUG "fuse 5 exit\n"); // fuse_ctl_cleanup(); 
example_exit2();
// fuse_sysfs_cleanup(); //fuse_fs_cleanup(); fuse_dev_cleanup(); 
}
module_init(fuse_init); module_exit(fuse_exit);




 MODULE_AUTHOR("Miklos Szeredi <miklos@szeredi.hu>"); MODULE_DESCRIPTION("Filesystem in Userspace"); MODULE_LICENSE("GPL");