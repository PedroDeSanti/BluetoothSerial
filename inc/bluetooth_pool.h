#ifndef __BLUETOOTH_POOL_H__
#define __BLUETOOTH_POOL_H__

#include <map>
#include <string>
#include <cstdint>
#include "bluetooth_var.h"

/*****************************************
 * Class Definition
 *****************************************/

class BluetoothPool {
    public:
        static BluetoothPool* get_instance();

    private:
        static BluetoothPool* instance;

        BluetoothPool() { }

        std::map<uint16_t, BluetoothVar<int>*> var_id_to_name;
};

#endif // __BLUETOOTH_POOL_H__
