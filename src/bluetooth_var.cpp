#ifndef __BLUETOOTH_VAR_CPP__
#define __BLUETOOTH_VAR_CPP__

#include "bluetooth_var.h"

static uint16_t current_var_id = 0;

template <class T>
BluetoothVar<T>::BluetoothVar(std::string var_name, T var_value) {
    this->var_id = current_var_id++;
    this->var_name = var_name;
    this->var_value = var_value;
    this->is_read_only = false;

    this->var_size = sizeof(T) / sizeof(uint8_t);

    add_var_to_packet();
}

template <class T>
BluetoothVar<T>::BluetoothVar(std::string var_name) {
    this->var_id = current_var_id++;
    this->var_name = var_name;
    this->var_value = 0;
    this->is_read_only = true;

    add_var_to_packet();
}

template <class T>
T BluetoothVar<T>::get_value() {
    return this->var_value;
}

template <class T>
void BluetoothVar<T>::update_var() {
    if (this->is_read_only) {
        update_packet(this->var_id, this->var_value);
    } else {
        this->var_value = read_from_packet(this->var_id);
    }
}

template <class T>
void BluetoothVar<T>::add_var_to_packet() {
    (void) 0;
}

template <class T>
void BluetoothVar<T>::update_packet(uint16_t var_id, T var_value) {
    (void) var_id;
    (void) var_value;
}

template <class T>
T BluetoothVar<T>::read_from_packet(uint16_t var_id) {
    (void) var_id;
    return 0;
}

// Operators override

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator =(T var_value) {
    this->var_value = var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator +(T var_value) {
    this->var_value += var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator -(T var_value) {
    this->var_value -= var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator ++(int) {
    this->var_value++;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator --(int) {
    this->var_value--;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator ++() {
    ++this->var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator --() {
    --this->var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator +=(T var_value) {
    this->var_value += var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator -=(T var_value) {
    this->var_value -= var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator *=(T var_value) {
    this->var_value *= var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator /=(T var_value) {
    this->var_value /= var_value;
    return *this;
}

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator %=(uint16_t var_value){}

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator &=(uint16_t var_value){}

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator |=(uint16_t var_value){}

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator ^=(uint16_t var_value){}

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator <<=(uint16_t var_value){}

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator >>=(uint16_t var_value){}

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator ~(){}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator !() {
    !this->var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator &&(T var_value) {
    this->var_value && var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator ||(T var_value) {
    this->var_value || var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator ==(T var_value) {
    this->var_value == var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator !=(T var_value) {
    this->var_value != var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator >(T var_value) {
    this->var_value > var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator <(T var_value) {
    this->var_value < var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator >=(T var_value) {
    this->var_value >= var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator <=(T var_value) {
    this->var_value <= var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator =(BluetoothVar<T> var) {
    this->var_value = var.var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator +(BluetoothVar<T> var) {
    this->var_value += var.var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator -(BluetoothVar<T> var) {
    this->var_value -= var.var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator +=(BluetoothVar<T> var) {
    this->var_value += var.var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator -=(BluetoothVar<T> var) {
    this->var_value -= var.var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator *=(BluetoothVar<T> var) {
    this->var_value *= var.var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator /=(BluetoothVar<T> var) {
    this->var_value /= var.var_value;
    return *this;
}

template <class T>
BluetoothVar<T> BluetoothVar<T>::operator %=(BluetoothVar<T> var) {
    this->var_value %= var.var_value;
    return *this;
}

#endif // __BLUETOOTH_VAR_CPP__
