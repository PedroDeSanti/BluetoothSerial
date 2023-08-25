#include "bluetooth_pool.h"

BluetoothPool::BluetoothPool() {
}

BluetoothPool* BluetoothPool::get_instance() {
    static BluetoothPool instance;
    return &instance;

    // if (instance == nullptr) {
    // instance = new BluetoothPool();
    // }
    // return instance;
}
