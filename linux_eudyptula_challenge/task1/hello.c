/*
 * hello.c - A simple kernel module
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EK");
MODULE_DESCRIPTION("Eudyptula Challenge Task 1: Hello World");

static int __init hello_init(void)
{
    printk(KERN_DEBUG "Hello World!\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_DEBUG "Remove hello.ko module\n");
}

module_init(hello_init);
module_exit(hello_exit);
