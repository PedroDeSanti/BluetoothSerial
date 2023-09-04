#include "bluetooth_pool.h"

BluetoothPool* BluetoothPool::instance = 0;

BluetoothPool* BluetoothPool::get_instance() {
    static BluetoothPool instance;
    return &instance;
}

void BluetoothPool::add_var(uint16_t var_id, ISerializable* var) {
    this->var_id_map[var_id] = var;
}

ISerializable* BluetoothPool::get_var(uint16_t var_id) {
    return this->var_id_map[var_id];
}
