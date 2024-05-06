#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/fs.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("SALLY & DALIA");
MODULE_DESCRIPTION("Our First Character Driver");

/* global variable for the device number */
static dev_t first;

static int ofd_init(void)
{
	printk(KERN_INFO "NAMSAKAR:ofd reg");
	if(alloc_chrdev_region(&first, 0, 3, "Mahesh") <0)
	{
		return -1;
	}
	printk(KERN_INFO "<Major,Minor>: <%d ,%d> \n",MAJOR(first),MINOR(first));
	return 0;
}

static void ofd_exit(void)
{
	unregister_chrdev_region(first,3);
	printk(KERN_INFO "by Gn:ofd unreg");
}

module_init(ofd_init);
module_exit(ofd_exit);
