#include "ToyMinorClass.h"

#include <map>

std::map<uint8_t, std::string> cod_minor_device_class_map_toy = {
    {0x00, "Uncategorized"},
    {0x01, "Robot"},
    {0x02, "Vehicle"},
    {0x03, "Doll / Action Figure"},
    {0x04, "Controller"},
    {0x05, "Game"},
    {0x06, "Puzzle"},
    {0x07, "Toy - Unknown"},
};

ToyMinorClass::ToyMinorClass(uint32_t cod)
{
    m_cod = cod;
    m_minor_device_class = getMinorDeviceClassCode(cod); // Extract minor device class (bit 6,7)
}

ToyMinorClass::~ToyMinorClass()
{
    
}

std::string ToyMinorClass::getMinorDeviceClass() const 
{
    auto it = cod_minor_device_class_map_toy.find(m_minor_device_class);
    if (it != cod_minor_device_class_map_toy.end()) {
        return it->second;
    }
    return "Unknown";
}


