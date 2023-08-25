#include "bluetooth_serial.h"
#include "dma.h"
#include "usart.h"

BluetoothSerial::BluetoothSerial(UART_HandleTypeDef* uart_handle) {
    MX_DMA_Init();
    MX_USART1_UART_Init();
    HAL_UART_Receive_DMA(uart_handle, this->rx_data, PACKET_SIZE);

    HAL_UART_RegisterCallback(uart_handle, HAL_UART_RX_COMPLETE_CB_ID, uartRxCallbackProxy);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart) {
    (void) huart;
}

// void BluetoothSerial::rx_callback(UART_HandleTypeDef* huart) {
// (void) huart;

// if (this->is_map_request()) {

// this->send_map();
// } else {
// this->update_var();
// }
// }

void BluetoothSerial::uartRxCallbackProxy(UART_HandleTypeDef* huart) {
    (void) huart;
}

void BluetoothSerial::uartRxCallback() {
    if (is_map_request()) {
        send_map();
    } else {
        update_var();
    }
}

bool BluetoothSerial::is_map_request() {
    return this->rx_data[0] == 0x00;
}

void BluetoothSerial::send_map() {
    (void) 0;
}

void BluetoothSerial::update_var() {
    (void) 0;
}
