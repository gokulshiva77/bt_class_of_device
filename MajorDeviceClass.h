#ifndef MAJORDEVICECLASS_H
#define MAJORDEVICECLASS_H

#include <cstdint>
#include <string>

enum class MajorDeviceClassType : uint8_t
{
    Miscellaneous = 0x00,
    Computer = 0x01,
    Phone = 0x02,
    LAN_Network_Access_Point = 0x03,
    Audio_Video = 0x04,
    Peripheral = 0x05,
    Imaging = 0x06,
    Wearable = 0x07,
    Toy = 0x08,
    Health = 0x09,
    Uncategorized = 0x1F
};

class MajorDeviceClass
{
public:
    MajorDeviceClass(uint32_t cod);
    ~MajorDeviceClass();
    std::string getMajorDeviceClass() const;
    MajorDeviceClassType getMajorDeviceClassType() const;
private:
    uint32_t m_cod;
    uint8_t m_major_device_class;
};


#endif // MAJORDEVICECLASS_H