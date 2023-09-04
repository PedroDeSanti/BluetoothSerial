#ifndef __BLUETOOTH_VAR_CPP__
#define __BLUETOOTH_VAR_CPP__

#include "bluetooth_var.h"
#include "bluetooth_pool.h"

static uint16_t current_var_id = 0;

template <class T>
BluetoothVar<T>::BluetoothVar(std::string var_name, T var_value) {
    this->id = current_var_id++;
    this->var_name = var_name;
    this->var_value = var_value;
    this->is_read_only = false;

    this->var_size = sizeof(T);

    BluetoothPool::get_instance()->add_var(this->id, this);
}

template <class T>
BluetoothVar<T>::BluetoothVar(std::string var_name) {
    this->id = current_var_id++;
    this->var_name = var_name;
    this->var_value = 0;
    this->is_read_only = true;

    this->var_size = sizeof(T);

    BluetoothPool::get_instance()->add_var(this->id, this);
}

template <class T>
uint8_t* BluetoothVar<T>::serialize() {
    return (uint8_t*) (&this->var_value);
}

template <class T>
IObject BluetoothVar<T>::deserialize() {
    (void) 0;
}

template <class T>
uint8_t BluetoothVar<T>::get_size() {
    return this->var_size;
}

template <class T>
T BluetoothVar<T>::get_value() {
    return this->var_value;
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

template <class T>
bool BluetoothVar<T>::operator !() {
    return (!this->var_value);
}

template <class T>
bool BluetoothVar<T>::operator &&(T var_value) {
    return (this->var_value && var_value);
}

template <class T>
bool BluetoothVar<T>::operator ||(T var_value) {
    return (this->var_value || var_value);
}

template <class T>
bool BluetoothVar<T>::operator ==(T var_value) {
    return (this->var_value == var_value);
}

template <class T>
bool BluetoothVar<T>::operator !=(T var_value) {
    return (this->var_value != var_value);
}

template <class T>
bool BluetoothVar<T>::operator >(T var_value) {
    return (this->var_value > var_value);
}

template <class T>
bool BluetoothVar<T>::operator <(T var_value) {
    return (this->var_value < var_value);
}

template <class T>
bool BluetoothVar<T>::operator >=(T var_value) {
    return (this->var_value >= var_value);
}

template <class T>
bool BluetoothVar<T>::operator <=(T var_value) {
    return (this->var_value <= var_value);
}

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator =(BluetoothVar<T> var) {
// this->var_value = var.var_value;
// return *this;
// }

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator +(BluetoothVar<T> var) {
// this->var_value += var.var_value;
// return *this;
// }

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator -(BluetoothVar<T> var) {
// this->var_value -= var.var_value;
// return *this;
// }

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator +=(BluetoothVar<T> var) {
// this->var_value += var.var_value;
// return *this;
// }

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator -=(BluetoothVar<T> var) {
// this->var_value -= var.var_value;
// return *this;
// }

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator *=(BluetoothVar<T> var) {
// this->var_value *= var.var_value;
// return *this;
// }

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator /=(BluetoothVar<T> var) {
// this->var_value /= var.var_value;
// return *this;
// }

// template <class T>
// BluetoothVar<T> BluetoothVar<T>::operator %=(BluetoothVar<T> var) {
// this->var_value %= var.var_value;
// return *this;
// }

#endif // __BLUETOOTH_VAR_CPP__
