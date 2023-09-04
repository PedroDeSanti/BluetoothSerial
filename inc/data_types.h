#ifndef __DATA_TYPES_H__
#define __DATA_TYPES_H__

#include <cstdint>
#include <string>

class IObject {
    public:

    protected:
};

class String :
    public IObject {
};

class UInt8 :
    public IObject {
    public:
        UInt8 operator =(UInt8 obj);

        UInt8 operator =(uint8_t obj);

        UInt8 operator +(UInt8 obj);

        UInt8 operator -(uint8_t obj);

        UInt8 operator -(UInt8 obj);

        UInt8 operator *(UInt8 obj);

        UInt8 operator /(UInt8 obj);

        UInt8 operator %(UInt8 obj);

        UInt8 operator +=(UInt8 obj);

        UInt8 operator -=(UInt8 obj);

        UInt8 operator *=(UInt8 obj);

        UInt8 operator /=(UInt8 obj);

        UInt8 operator %=(UInt8 obj);

        UInt8 operator ++();

        UInt8 operator --();

        UInt8 operator ++(int);

        UInt8 operator --(int);

        UInt8 operator -();

        UInt8 operator +();

        UInt8 operator ==(UInt8 obj);

        UInt8 operator !=(UInt8 obj);

        UInt8 operator >(UInt8 obj);

        UInt8 operator <(UInt8 obj);

        UInt8 operator >=(UInt8 obj);

        UInt8 operator <=(UInt8 obj);
};

class Int8 :
    public IObject {
};

class UInt16 :
    public IObject {
};

class Int16 :
    public IObject {
};

class UInt32 :
    public IObject {
};

class Int32 :
    public IObject {
};

class UInt64 :
    public IObject {
};

class Int64 :
    public IObject {
};

class Float :
    public IObject {
};

class Double :
    public IObject {
};

class Boolean :
    public IObject {
};

#endif // __DATA_TYPES_H__
