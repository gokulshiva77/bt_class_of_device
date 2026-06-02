#include "ClassOfDevice.h"

#include <iostream>

ClassOfDevice::ClassOfDevice(uint32_t cod):
    m_service_class(cod),
    m_major_class(cod), 
    m_cod(cod),
    m_minor_class_factory()
{
    m_cod = cod;
    m_minor_class = m_minor_class_factory.createMinorClass(m_major_class.getMajorDeviceClassType(), cod);
}

ClassOfDevice::~ClassOfDevice()
{
    // Minor class will be automatically deleted due to unique_ptr
}

void ClassOfDevice::PrintClassOfDevice() const
{
    std::cout << "Class of Device: 0x" << std::hex << m_cod << std::endl;
    std::cout << "Service Class: " << m_service_class.getServiceClass() << std::endl;
    std::cout << "Major Device Class: " << m_major_class.getMajorDeviceClass() << std::endl;
    if (m_minor_class) {
        std::cout << "Minor Device Class: " << m_minor_class->getMinorDeviceClass() << std::endl;
    }
}
