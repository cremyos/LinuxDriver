#ifndef	__SIMPLE_H_INCLUDE__
#define __SIMPLE_H_INCLUDE__

#include <linux/ioctl.h>

/**
 * print debug information
 */
#undef	PDEBUG
#ifdef	simple_DEBUG
#ifdef	__KERNEL__
#	define PDEBUG(fmt, args...) printk(KERN_DEBUG "DEMO: " fmt, ##args)
#else
#	define PDEBUG(fmt, args...) fprintf(stderr, fmt, ##args)
#endif
#else
#	define PDEBUG(fmt, args...) /* not debuging: nothing*/
#endif

#undef PDEBUG
#define PDEBUG(fmt, args...) /* nothing: it's a placeholder*/

#define simple_MAJOR 224

/**
 * Function Declare
 */
int simple_open(struct inode *inode, struct file *filp);	/// Open Device File

int simple_release(struct inode *inode, struct file *filp);	/// release file

ssize_t simple_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos);	/// read device file

loff_t simple_llseek(struct file *filp, loff_t off, int whence);	/// Location file

int simple_ioctl(struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg);	/// control device

#endif
