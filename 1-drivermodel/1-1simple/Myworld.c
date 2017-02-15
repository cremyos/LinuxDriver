#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/init.h>

static int demo_module_init(void)
{
	printk("Init\n");
	return 0;
}

static void demo_module_exit(void)
{
	printk("Exit\n");
}

module_init(demo_module_init);
module_exit(demo_module_exit);

MODULE_DESCRIPTION("Simple Module");
MODULE_LICENSE("GPL");
