#include "HealthMinorClass.h"

#include <map>

std::map<uint8_t, std::string> cod_minor_device_class_map_health = {
    {0x00, "Uncategorized"},
    {0x01, "Blood Pressure Monitor"},
    {0x02, "Thermometer"},
    {0x03, "Weighing Scale"},
    {0x04, "Glucose Meter"},
    {0x05, "Pulse Oximeter"},
    {0x06, "Heart Rate Monitor"},
    {0x07, "Health Data Display"},
    {0x08, "Step Counter"},
    {0x09, "Body Composition Analyzer"},
    {0x0A, "Peak Flow Monitor"},
    {0x0B, "Medication Monitor"},
    {0x0C, "Knee Prosthesis"},
    {0x0D, "Ankle Prosthesis"},
    {0x0E, "Generic Health Manager"},
    {0x0F, "Personal Mobility Device"}
};

HealthMinorClass::HealthMinorClass(uint32_t cod)
{
    m_cod = cod;
    m_minor_device_class = getMinorDeviceClassCode(cod); // Extract minor device class (bit 6,7)
}

HealthMinorClass::~HealthMinorClass()
{
    
}

std::string HealthMinorClass::getMinorDeviceClass() const 
{
    auto it = cod_minor_device_class_map_health.find(m_minor_device_class);
    if (it != cod_minor_device_class_map_health.end()) {
        return it->second;
    }
    return "Unknown";
}

