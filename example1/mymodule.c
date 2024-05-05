#include<linux/init.h>
#include<linux/module.h>

/* Meta Information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("SALLY GNU/Linux");
MODULE_DESCRIPTION("Hello World LKM");

/**
 * @brief this function is called, when the module is loaded into the kernel
 */
 static int __init ModuleInit(void)
{
	printk("Hello Kernel!\n");
	return 0;
}

/**
 * @brief this function is called, when the module is removed from the kernel
 */

static void __exit ModuleExit(void)
{
	printk("GoodBy, Kernel\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);
