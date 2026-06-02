#include "MajorDeviceClass.h"
#include <map>

std::map<uint8_t, std::string> cod_major_device_class_map = {
    {0x00, "Miscellaneous"},
    {0x01, "Computer"},
    {0x02, "Phone"},
    {0x03, "LAN/Network Access Point"},
    {0x04, "Audio/Video"},
    {0x05, "Peripheral"},
    {0x06, "Imaging"},
    {0x07, "Wearable"},
    {0x08, "Toy"},
    {0x09, "Health"},
    {0x1F, "Uncategorized"}
};

MajorDeviceClass::MajorDeviceClass(uint32_t cod)
{
    m_cod = cod;
    m_major_device_class = (cod & 0x1F00) >> 8; // Extract major device class
}

MajorDeviceClass::~MajorDeviceClass()
{
    
}

std::string MajorDeviceClass::getMajorDeviceClass() const
{
    return cod_major_device_class_map[m_major_device_class];
}

MajorDeviceClassType MajorDeviceClass::getMajorDeviceClassType() const
{
    return static_cast<MajorDeviceClassType>(m_major_device_class);
}
