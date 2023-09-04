#ifndef __BLUETOOTH_POOL_H__
#define __BLUETOOTH_POOL_H__

#include <map>
#include <string>
#include <cstdint>
#include "serializable_interface.h"

/*****************************************
 * Class Definition
 *****************************************/

class BluetoothPool {
    public:
        static BluetoothPool* get_instance();

        void add_var(uint16_t var_id, ISerializable* var);

        ISerializable* get_var(uint16_t var_id);

        std::map<uint16_t, ISerializable*> var_id_map;

    private:
        static BluetoothPool* instance;

        BluetoothPool() { }
};

#endif // __BLUETOOTH_POOL_H__
