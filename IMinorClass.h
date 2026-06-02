#ifndef IMINORCLASS_H
#define IMINORCLASS_H

#include <string>
#include <cstdint>

#define MINOR_DEVICE_CLASS_MASK 0x00FC

class IMinorClass
{
public:
    virtual std::string getMinorDeviceClass() const = 0; // Pure virtual function
    virtual ~IMinorClass() = default; // Virtual destructor
    inline uint8_t getMinorDeviceClassCode(uint32_t cod) const {
        return (cod & MINOR_DEVICE_CLASS_MASK) >> 2; // Extract minor device class (bit 2-7)
    }
};

#endif // IMINORCLASS_H