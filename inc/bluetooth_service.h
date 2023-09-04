#ifndef __BLUETOOTH_SERVICE_H__
#define __BLUETOOTH_SERVICE_H__

#include <cstdint>
#include "bluetooth_pool.h"
#include "bluetooth_var.h"

/*****************************************
 * Class Definition
 *****************************************/

class BluetoothService {
    public:
        BluetoothService();

        void update();

    private:
        BluetoothPool* bluetooth_pool;
};

#endif // __BLUETOOTH_SERVICE_H__
