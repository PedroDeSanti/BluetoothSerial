#ifndef __SERIALIZABLE_INTERFACE_H__
#define __SERIALIZABLE_INTERFACE_H__

#include <cstdint>
#include "data_types.h"

class ISerializable {
    public:
        virtual uint8_t* serialize() = 0;

        // template <class T>
        // virtual T deserialize() = 0;

        virtual IObject deserialize() = 0;

        // size:
        virtual uint8_t get_size() = 0;

    protected:
};

#endif // __SERIALIZABLE_INTERFACE_H__
