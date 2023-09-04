#ifndef __BLUETOOTH_VAR_H__
#define __BLUETOOTH_VAR_H__

#include <cstdint>
#include <string>
#include <array>
#include <map>
#include "serializable_interface.h"
#include "data_types.h"

/*****************************************
 * Class Definition
 *****************************************/

template <class T>
class BluetoothVar :
    public ISerializable {
    public:
        BluetoothVar(std::string var_name, T var_value);

        BluetoothVar(std::string var_name);

        BluetoothVar<T> operator =(T var_value);

        BluetoothVar<T> operator +(T var_value);

        BluetoothVar<T> operator -(T var_value);

        BluetoothVar<T> operator ++(int);

        BluetoothVar<T> operator --(int);

        BluetoothVar<T> operator ++();

        BluetoothVar<T> operator --();

        BluetoothVar<T> operator +=(T var_value);

        BluetoothVar<T> operator -=(T var_value);

        BluetoothVar<T> operator *=(T var_value);

        BluetoothVar<T> operator /=(T var_value);

        bool operator !();

        bool operator &&(T var_value);

        bool operator ||(T var_value);

        bool operator ==(T var_value);

        bool operator !=(T var_value);

        bool operator >(T var_value);

        bool operator <(T var_value);

        bool operator >=(T var_value);

        bool operator <=(T var_value);

        // BluetoothVar<T> operator =(BluetoothVar<T> var);

        // BluetoothVar<T> operator +(BluetoothVar<T> var);

        // BluetoothVar<T> operator -(BluetoothVar<T> var);

        // BluetoothVar<T> operator +=(BluetoothVar<T> var);

        // BluetoothVar<T> operator -=(BluetoothVar<T> var);

        // BluetoothVar<T> operator *=(BluetoothVar<T> var);

        // BluetoothVar<T> operator /=(BluetoothVar<T> var);

        // BluetoothVar<T> operator %=(BluetoothVar<T> var);

        uint8_t* serialize();

        IObject deserialize();

        uint8_t get_size();

        T get_value();

    private:
        std::string var_name;
        uint16_t id;
        T var_value;
        bool is_read_only;

        uint8_t var_size;
};

#include "../src/bluetooth_var.cpp"

#endif // __BLUETOOTH_VAR_H__
