#include "ImagingMinorClass.h"

#include <map>

enum ImagingMinorIdx {
    IMAGING_MINOR_DEVICE_DISPLAY_IDX = 4,
    IMAGING_MINOR_DEVICE_CAMERA_IDX,
    IMAGING_MINOR_DEVICE_SCANNER_IDX,
    IMAGING_MINOR_DEVICE_PRINTER_IDX,
};

ImagingMinorClass::ImagingMinorClass(uint32_t cod)
{
    m_cod = cod;
    m_minor_device_class = (cod >> 6) & 0x03; // Extract minor device class (bit 6,7)
}

ImagingMinorClass::~ImagingMinorClass()
{
    
}

std::string ImagingMinorClass::getMinorDeviceClass() const 
{
    std::string output = "";
    if(m_minor_device_class & IMAGING_MINOR_DEVICE_DISPLAY_IDX)
    {
        output += "Display ";
    }
    else if(m_minor_device_class & IMAGING_MINOR_DEVICE_CAMERA_IDX)
    {
        output += "Camera ";
    }
    else if(m_minor_device_class & IMAGING_MINOR_DEVICE_SCANNER_IDX)
    {
        output += "Scanner ";
    }
    else if(m_minor_device_class & IMAGING_MINOR_DEVICE_PRINTER_IDX)
    {
        output += "Printer ";
    }
    return output;
}
