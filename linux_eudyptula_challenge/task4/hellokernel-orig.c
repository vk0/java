#include <linux/module.h> /*needed by all modules*/
#include <linux/kernel.h> /*needed for printk macros*/
#include <linux/init.h> /*needed for init macros*/
static int hello_init(void){

    printk(KERN_ALERT"Hello World!\n");
    return 0; // return a zero value to indicate success
}

static void hello_exit(void){
printk(KERN_ALERT"GOODBYE WORLD");
    return;
}

module_init(hello_init);
module_exit(hello_exit);