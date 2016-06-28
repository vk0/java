#include <linux/init.h>
#include <linux/module.h>

// http://lxr.free-electrons.com/source/include/linux/init.h
static int __init aufs_init(void)
{
    // http://lxr.free-electrons.com/source/Documentation/printk-formats.txt
    pr_debug("aufs module loaded\n");
    return 0;
}

static void __exit aufs_fini(void)
{
    pr_debug("aufs module unloaded\n");
}

// http://lxr.free-electrons.com/source/include/linux/init.h?v=3.14#L266
module_init(aufs_init);
module_exit(aufs_fini);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("kmu");