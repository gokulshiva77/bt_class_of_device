#include "PhoneMinorClass.h"
#include <map>

std::map<uint8_t, std::string> cod_minor_device_class_map_phone = {
    {0x00, "Uncategorized"},
    {0x01, "Cellular"},
    {0x02, "Cordless"},
    {0x03, "Smartphone"},
    {0x04, "Wired Modem or Voice Gateway"},
    {0x05, "Common ISDN Access"}
};

PhoneMinorClass::PhoneMinorClass(uint32_t cod)
{
    m_cod = cod;
    m_minor_device_class = getMinorDeviceClassCode(cod); // Extract minor device class
}

PhoneMinorClass::~PhoneMinorClass()
{
    
}

std::string PhoneMinorClass::getMinorDeviceClass() const 
{
    std::string output = "Reserved";
    try
    {
        output = cod_minor_device_class_map_phone.at(m_minor_device_class);
    }
    catch(const std::exception& e)
    {
        
    }
    return output;
}
