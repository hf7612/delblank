/*
 * Here's a sample kernel module showing the use of jprobes to dump
 * the arguments of _do_fork().
 *
 * For more information on theory of operation of jprobes, see
 * Documentation/kprobes.txt
 *
 * Build and insert the kernel module as done in the kprobe example.
 * You will see the trace data in /var/log/messages and on the
 * console whenever _do_fork() is invoked to create a new process.
 * (Some messages may be suppressed if syslogd is configured to
 * eliminate duplicate messages.)
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/slab.h>
/*
 * Jumper probe for _do_fork.
 * Mirror principle enables access to arguments of the probed routine
 * from the probe handler.
 */
// char *file_path(struct file *filp,char *buf,int buflen) { return d_path(&filp->f_path,buf,buflen); } EXPORT_SYMBOL(); /**  * vfs_open - open the file at the given path  * @path: path to open  * @file: newly allocated file with f_flag initialized  * @cred: credentials to use  */
// err
char pathbuf[PATH_MAX]={0};
static int j_vfs_open(const struct path *path,struct file *file,const struct cred *cred) { //struct dentry *dentry = d_real(path->dentry,NULL,file->f_flags); if (IS_ERR(dentry)) return PTR_ERR(dentry); file->f_path = *path; return do_dentry_open(file,d_backing_inode(dentry),NULL,cred); 
	// char *p 
	#if 1
	// printk(" joes line:%d \n ", __LINE__);
	// char *pathbuf = kmalloc(PATH_MAX, GFP_KERNEL);
	// printk(" joes line:%d \n ", __LINE__);
	// if(pathbuf){
		// printk(" joes line:%d \n ", __LINE__);
		// char *fp = 0;
		// if(file)// && file->f_path)
			// fp = file_path(file, pathbuf, PATH_MAX);
			// printk(" joes line:%d \n ", __LINE__);
			if (current->mm && path->dentry->d_iname[0] && file){
				printk(" joesf %s %s \n ", path->dentry->d_iname, file->f_path.dentry->d_iname);   
				// fp = file_path(file, pathbuf, PATH_MAX);
			}
			// printk(" 2joes line:%s \n ", file->f_path->dentry->d_iname);
		// pathbuf[4000] = 'f';
		// if(fp){ printk(" joes line:%d \n ", __LINE__); 
		// 	printk(" joes patch:%s \n", fp);
		// }else printk(" joes null3 \n "); 
		// printk(" joes line:%d \n ", __LINE__);
		// kfree(pathbuf);
	// }else{ printk(" joes null %s \n ", "ggg"); }
	// printk(" joes line: %p %p %p\n ", path, file, cred);
	jprobe_return(); return 0;
	#else
	printk(" joes patch %s \n",  "www"); 
	jprobe_return(); return 0;
	#endif
}
/* Proxy routine having the same arguments as actual _do_fork() routine */
// static long j_do_fork(unsigned long clone_flags, unsigned long stack_start, unsigned long stack_size, int __user *parent_tidptr, int __user *child_tidptr, unsigned long tls) { pr_info("jprobe: clone_flags = 0x%lx, stack_start = 0x%lx " "stack_size = 0x%lx\n", clone_flags, stack_start, stack_size); jprobe_return(); return 0; }

static struct jprobe my_jprobe = {
	.entry			= j_vfs_open, //j_do_fork,
	.kp = {
		.symbol_name	= "vfs_open", //"_do_fork",
	},
};

static int __init jprobe_init(void)
{
	int ret;

	ret = register_jprobe(&my_jprobe);
	if (ret < 0) {
		pr_err("register_jprobe failed, returned %d\n", ret);
		return -1;
	}
	pr_info("Planted jprobe at %p, handler addr %p\n",
	       my_jprobe.kp.addr, my_jprobe.entry);
	return 0;
}

static void __exit jprobe_exit(void)
{
	unregister_jprobe(&my_jprobe);
	pr_info("jprobe at %p unregistered\n", my_jprobe.kp.addr);
}

module_init(jprobe_init)
module_exit(jprobe_exit)
MODULE_LICENSE("GPL");
