#include "bluetooth_service.h"
#include "usart.h"

BluetoothService::BluetoothService() {
    MX_USART1_UART_Init();

    this->bluetooth_pool = BluetoothPool::get_instance();
}

void BluetoothService::update() {
    // send updated values
    uint8_t package[256];

    for (auto& var : this->bluetooth_pool->var_id_map) {
        package[0] = 0x7E;
        package[1] = var.first;

        for (int i = 0; i < var.second->get_size(); i++) {
            package[i + 2] = var.second->serialize()[i];
        }

        package[var.second->get_size() + 2] = 0x7F;

        HAL_UART_Transmit(&huart1, package, var.second->get_size() + 3, 1000);
    }
}
