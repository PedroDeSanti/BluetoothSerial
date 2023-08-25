#ifndef __BLUETOOTH_VAR_H__
#define __BLUETOOTH_VAR_H__

#include <cstdint>
#include <string>
#include <array>
#include <map>
#include "serializable_interface.h"

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

        BluetoothVar<T> operator !();

        BluetoothVar<T> operator &&(T var_value);

        BluetoothVar<T> operator ||(T var_value);

        BluetoothVar<T> operator ==(T var_value);

        BluetoothVar<T> operator !=(T var_value);

        BluetoothVar<T> operator >(T var_value);

        BluetoothVar<T> operator <(T var_value);

        BluetoothVar<T> operator >=(T var_value);

        BluetoothVar<T> operator <=(T var_value);

        BluetoothVar<T> operator =(BluetoothVar<T> var);

        BluetoothVar<T> operator +(BluetoothVar<T> var);

        BluetoothVar<T> operator -(BluetoothVar<T> var);

        BluetoothVar<T> operator +=(BluetoothVar<T> var);

        BluetoothVar<T> operator -=(BluetoothVar<T> var);

        BluetoothVar<T> operator *=(BluetoothVar<T> var);

        BluetoothVar<T> operator /=(BluetoothVar<T> var);

        BluetoothVar<T> operator %=(BluetoothVar<T> var);

        T get_value();

        void update_var();

    private:
        void add_var_to_packet();

        void update_packet(uint16_t var_id, T var_value);

        T read_from_packet(uint16_t var_id);

        std::string var_name;
        uint16_t var_id;
        T var_value;
        bool is_read_only;

        uint8_t var_size;

        static std::array<BluetoothVar*, 100> bluetooth_var_pool;
        static std::map<uint16_t, BluetoothVar*> var_id_to_name;
};

#include "../src/bluetooth_var.cpp"

#endif // __BLUETOOTH_VAR_H__
