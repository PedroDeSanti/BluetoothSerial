/**
 * @file main.c
 *
 * @brief Main function
 */

#include "mcu.h"
#include "bluetooth_var.h"
#include "bluetooth_service.h"

/*****************************************
 * Private Constant Definitions
 *****************************************/

#define LED_TOGGLE_DELAY_MS 1500

BluetoothVar<uint32_t> led_toggle_delay_ms("led_toggle_delay_ms", 500);
BluetoothVar<uint32_t> counter("counter");

/*****************************************
 * Main Function
 *****************************************/

int main(void) {
    mcu_init();
    BluetoothService bluetooth_service = BluetoothService();

    counter = 0;

    for (;;) {
        led_toggle();

        if (counter < 100) {
            counter++;
        } else {
            counter--;
        }

        mcu_sleep(led_toggle_delay_ms.get_value());

        bluetooth_service.update();
    }
}
