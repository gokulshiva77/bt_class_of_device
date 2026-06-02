#include "PeripheralMinorClass.h"

#include <map>
std::map<uint8_t, std::string> cod_minor_device_class_map_peripheral = {
    {0x00, "Not Keyboard / Not Pointing Device"},
    {0x01, "Keyboard"},
    {0x02, "Pointing Device"},
    {0x03, "Combo keyboard/pointing device"},
};

std::map<uint8_t, std::string> cod_minor_sub_device_class_map_peripheral = {
    {0x00, "Uncategorized"},
    {0x01, "Joystick"},
    {0x02, "Gamepad"},
    {0x03, "Remote Control"},
    {0x04, "Sensing Device"},
    {0x05, "Digitizer Tablet"},
    {0x06, "Card Reader"},
    {0x07, "Digital Pen"},
    {0x08, "Handheld Scanner"},
    {0x09, "Handheld Gesture Input Device"}
};

PeripheralMinorClass::PeripheralMinorClass(uint32_t cod)
{
    m_cod = cod;
    m_minor_device_class = (cod >> 6) & 0x03; // Extract minor device class (bit 6,7)
    m_minor_sub_device_class = (cod >> 2) & 0x0F; // Extract minor sub device class (bit 2,3,4,5)
}

PeripheralMinorClass::~PeripheralMinorClass()
{
    
}

std::string PeripheralMinorClass::getMinorDeviceClass() const 
{
    return cod_minor_device_class_map_peripheral[m_minor_device_class] + " - " + cod_minor_sub_device_class_map_peripheral[m_minor_sub_device_class];
}

