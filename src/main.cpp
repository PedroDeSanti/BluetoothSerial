/**
 * @file main.c
 *
 * @brief Main function
 */

#include "mcu.h"
#include "bluetooth_var.h"

/*****************************************
 * Private Constant Definitions
 *****************************************/

#define LED_TOGGLE_DELAY_MS 1500

BluetoothVar led_toggle_delay_ms = BluetoothVar("led_toggle_delay_ms", 1500);
BluetoothVar counter = BluetoothVar("counter");

/*****************************************
 * Main Function
 *****************************************/

int main(void) {
    mcu_init();

    for (;;) {
        led_toggle();
        mcu_sleep(led_toggle_delay_ms.get_value());

        if (counter.get_value() < 20) {
            counter++;
        } else {
            counter--;
        }

        // updateoh
    }
}
