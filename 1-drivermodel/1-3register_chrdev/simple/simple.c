#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/fcntl.h>
#include <linux/cdev.h>
#include <linux/version.h>
#include <linux/vmalloc.h>
#include <linux/ctype.h>
#include <linux/pagemap.h>

#include "simple.h"

MODULE_AUTHOR("Lniper");
MODULE_LICENSE("GPL");

#if 1
static unsigned char simple_inc = 0;
static unsigned char demoBuffer[256];
#endif


/**
 * open Device file
 */
int simple_open(struct inode *inode, struct file *filp)
{
	if(simple_inc > 0) {
		return -ERESTARTSYS;
	}

	simple_inc++;

	return 0;
}

/**
 * close Device file
 */
int simple_release(struct inode *inode, struct file *filp)
{
	simple_inc--;

	return 0;
}

/**
 * Read device file
 */
ssize_t simple_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	/**
	 * copy data to user space
	 */
	if(copy_to_user(buf, demoBuffer, count)) {
		count = -EFAULT;
	}

	return count;
}

/**
 * write Device file
 */
ssize_t simple_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	/**
	 * copy data to kernel
	 */
	if(copy_from_user(demoBuffer + *f_pos, buf, count)) {
		count = -EFAULT;
	}

	return count;
}

struct file_operations simple_fops =
{
	.owner = THIS_MODULE,
	.read = simple_read,
	.write = simple_write,
	.open = simple_open,
	.release = simple_release,
};


static int __init simple_setup_module(void)
{
	int ret = -1;

	ret = register_chrdev(simple_MAJOR, "simple", &simple_fops);
	if(ret < 0) {
		printk("<0>""Unable to register character device %d!\n", simple_MAJOR);
		return ret;
	}

	printk("<0>" "Register character device simple major(%d)\n", simple_MAJOR);

	//	printk("<1>""Register character device simple major(%d)");
	return 0;
}

static void __exit simple_cleanup_module(void)
{
	unregister_chrdev(simple_MAJOR, "simple");
	printk("<0>" "simple_cleanup_module!\n");
}

module_init(simple_setup_module);
module_exit(simple_cleanup_module);

/**
 * Device Information
 */
#define DRIVER_VERSION	"1.0.0"
#define DRIVER_AUTHOR	"Lniper"
#define DRIVER_DESC		"Linux Driver CHRDEV"
#define DRIVER_LICENSE	"GPL"


MODULE_VERSION(DRIVER_VERSION);
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_AUTHOR(DRIVER_DESC);
MODULE_AUTHOR(DRIVER_LICENSE);
	 	 
