#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio.h>

#define DRV_NAME "GPIO Bare"
#define PFX DRV_NAME ": "
#define GPIO_TEST_PIN 12

static int __init mymodule_init(void) {
    int err;
    printk(KERN_INFO PFX "AAAAAAAAAAA\n"); 
    return 0;
}

static void __exit mymodule_exit(void) {
   printk (KERN_INFO PFX "freeing GPIO %d\n", GPIO_TEST_PIN);
   gpio_free(GPIO_TEST_PIN);
   return;
}

module_init(mymodule_init);
module_exit(mymodule_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mister X");
