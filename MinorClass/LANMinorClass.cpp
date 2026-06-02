#include "LANMinorClass.h"
#include <map>

std::map<uint8_t, std::string> cod_minor_device_class_map_lan = {
    {0x00, "Uncategorized"},
    {0x01, "Fully Available"},
    {0x02, "1% to 17% Utilized"},
    {0x03, "17% to 33% Utilized"},
    {0x04, "33% to 50% Utilized"},
    {0x05, "50% to 67% Utilized"},
    {0x06, "67% to 83% Utilized"},
    {0x07, "83% to 99% Utilized"},
    {0x08, "No Service Available"}
};

LANMinorClass::LANMinorClass(uint32_t cod)
{
    m_cod = cod;
    m_minor_device_class = (cod >> 5) & 0x03;
}

LANMinorClass::~LANMinorClass()
{
    
}

std::string LANMinorClass::getMinorDeviceClass() const 
{
    auto it = cod_minor_device_class_map_lan.find(m_minor_device_class);
    if (it != cod_minor_device_class_map_lan.end()) {
        return it->second;
    }
    return "Unknown";
}
