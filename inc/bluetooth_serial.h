// #ifndef __BLUETOOTH_SERIAL_H__
// #define __BLUETOOTH_SERIAL_H__

// #include <cstdint>
// #include <string>
// #include <map>
// #include "usart.h"

// #define PACKET_SIZE 64

/// *****************************************
// * Class Definition
// *****************************************/

// class BluetoothSerial {
// public:
// BluetoothSerial(UART_HandleTypeDef* uart_handle);

// static void uartRxCallbackProxy(UART_HandleTypeDef* huart);

// private:
// void send_data();

// void update_var();

// bool is_map_request();

//// void rx_callback(UART_HandleTypeDef* huart);

//// static void uartRxCallbackProxy(BluetoothSerial* instance) {
//// instance->uartRxCallback();
//// }

//// void uartRxCallback();

// UART_HandleTypeDef* uart_handle;

// uint8_t rx_data[PACKET_SIZE];
// uint8_t tx_data[PACKET_SIZE];

// std::map<uint16_t, std::string> var_id_to_name;
// };

// #endif // __BLUETOOTH_SERIAL_H__
