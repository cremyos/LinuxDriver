#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/init.h>

static int demo_module_init(void)
{
	printk("<0>Module Init\n");
	return 0;
}

static void demo_module_exit(void)
{
	printk("<0>" "Module Exit\n");
}

/**
 * 模块初始化接口，参数表示自己的初始化函数
 */
module_init(demo_module_init);
/**
 * 模块卸载接口，参数表示自己的退出函数
 */
module_exit(demo_module_exit);

MODULE_DESCRIPTION("Simple Module");
MODULE_LICENSE("GPL");
