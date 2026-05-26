/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/gpio.h>

/* The nrf52840dk has an LED built-in called "led0" in its devicetree */
#define LED0_NODE DT_ALIAS(led0)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void)
{
    int ret;

    printk("VR Tracker App Initializing...\n");

    /* Check if the hardware LED is ready */
    if (!gpio_is_ready_dt(&led)) {
        printk("Error: Built-in LED device is not ready\n");
        return 0;
    }

    /* Configure the LED pin as an output */
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printk("Error: Could not configure LED pin (%d)\n", ret);
        return 0;
    }

    printk("Success! VR Tracker baseline code running smoothly.\n");

    while (1) {
        /* Toggle the LED on and off every 500ms */
        gpio_pin_toggle_dt(&led);
        k_msleep(500);
    }

    return 0;
}