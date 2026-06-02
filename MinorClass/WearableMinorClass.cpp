#include "WearableMinorClass.h"

#include <map>

std::map<uint8_t, std::string> cod_minor_device_class_map_wearable = {
    {0x00, "Uncategorized"},
    {0x01, "Wristwatch"},
    {0x02, "Pager"},
    {0x03, "Jacket"},
    {0x04, "Helmet"},
    {0x05, "Glasses"}
};

WearableMinorClass::WearableMinorClass(uint32_t cod)
{
    m_cod = cod;
    m_minor_device_class = getMinorDeviceClassCode(cod); // Extract minor device class (bit 6,7)
}

WearableMinorClass::~WearableMinorClass()
{
    
}

std::string WearableMinorClass::getMinorDeviceClass() const 
{
    auto it = cod_minor_device_class_map_wearable.find(m_minor_device_class);
    if (it != cod_minor_device_class_map_wearable.end()) {
        return it->second;
    }
    return "Unknown";
}
