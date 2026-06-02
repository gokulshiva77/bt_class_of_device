#include "ComputerMinorClass.h"
#include <map>

std::map<uint8_t, std::string> cod_minor_device_class_map_computer = {
    {0x00, "Uncategorized"},
    {0x01, "Desktop"},
    {0x02, "Server"},
    {0x03, "Laptop"},
    {0x04, "Handheld"},
    {0x05, "Palm Size"},
    {0x06, "Wearable"},
    {0x07, "Tablet"}
};

ComputerMinorClass::ComputerMinorClass(uint32_t cod)
{
    m_cod = cod;
    m_minor_device_class = getMinorDeviceClassCode(cod); // Extract minor device class
}

ComputerMinorClass::~ComputerMinorClass()
{
    
}

std::string ComputerMinorClass::getMinorDeviceClass() const 
{
    return cod_minor_device_class_map_computer[m_minor_device_class];
}
