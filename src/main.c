#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

#define LED1_NODE DT_NODELABEL(led1)
#define BUTTON1_NODE DT_NODELABEL(button1)

int main(void) {
    static const struct gpio_dt_spec led1_dev    = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
    static const struct gpio_dt_spec button1_dev = GPIO_DT_SPEC_GET(BUTTON1_NODE, gpios);

    gpio_pin_configure_dt(&led1_dev, GPIO_OUTPUT);
    gpio_pin_configure_dt(&button1_dev, GPIO_INPUT);
    for (;;) {

        bool button1_pressed = gpio_pin_get_dt(&button1_dev);
        gpio_pin_set_dt(&led1_dev, button1_pressed);
        k_msleep(50);
    }
    return 0;
}
