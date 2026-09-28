#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>


/* The devicetree node identifier for the "led0" alias. */
#define LED_NODE DT_ALIAS(led0)
#define LED_WARN_NODE DT_ALIAS(led1)
#define LED_BLUE_NODE DT_ALIAS(led2)
#define LED_RED_NODE DT_ALIAS(led3)


static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);
static const struct gpio_dt_spec warn_led = GPIO_DT_SPEC_GET(LED_WARN_NODE, gpios);
static const struct gpio_dt_spec blue_led = GPIO_DT_SPEC_GET(LED_BLUE_NODE, gpios);
static const struct gpio_dt_spec red_led = GPIO_DT_SPEC_GET(LED_RED_NODE, gpios);


LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

int main(void)
{
    bool led_state = true;
    bool warn_led_state = true;
    bool blue_led_state = true;
    bool red_led_state = true;

    if (!gpio_is_ready_dt(&led)) return 0;
    if (!gpio_is_ready_dt(&warn_led)) return 0;
    if (!gpio_is_ready_dt(&blue_led)) return 0;
    if (!gpio_is_ready_dt(&red_led)) return 0;




    if (gpio_pin_configure_dt(&warn_led, GPIO_OUTPUT_ACTIVE) < 0) return 0;
    if (gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE) < 0) return 0;
    if (gpio_pin_configure_dt(&blue_led, GPIO_OUTPUT_ACTIVE) < 0) return 0;
    if (gpio_pin_configure_dt(&red_led, GPIO_OUTPUT_ACTIVE) < 0) return 0;

    while (1) {
        if (gpio_pin_toggle_dt(&led) < 0) return 0;

        led_state = !led_state;
        LOG_INF("LED state: %s", led_state ? "ON" : "OFF");
        k_msleep(CONFIG_BLINK_SLEEP_TIME_MS);
        
        if (gpio_pin_toggle_dt(&warn_led) < 0) return 0;

        warn_led_state = !warn_led_state;
        LOG_INF("LED state: %s", warn_led_state ? "ON" : "OFF");
        k_msleep(CONFIG_BLINK_SLEEP_TIME_MS);
        
        if (gpio_pin_toggle_dt(&blue_led) < 0) return 0;

        blue_led_state = !blue_led_state;
        LOG_INF("LED state: %s", blue_led_state ? "ON" : "OFF");
        k_msleep(CONFIG_BLINK_SLEEP_TIME_MS);
        
        if (gpio_pin_toggle_dt(&red_led) < 0) return 0;

        red_led_state = !red_led_state;
        LOG_INF("LED state: %s", red_led_state ? "ON" : "OFF");
        k_msleep(CONFIG_BLINK_SLEEP_TIME_MS);


    }
    return 0;
}
