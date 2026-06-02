#ifndef CLASSOFDEVICE_H
#define CLASSOFDEVICE_H

#include<memory>

#include "ServiceClass.h"
#include "MajorDeviceClass.h"
#include "MinorClassFactory.h"
#include "IMinorClass.h"

#include "HealthMinorClass.h"

class ClassOfDevice
{
public:
    ClassOfDevice(uint32_t cod);
    ~ClassOfDevice();

    void PrintClassOfDevice() const;
private:
    uint32_t m_cod;
    ServiceClass m_service_class;
    MajorDeviceClass m_major_class;
    MinorClassFactory m_minor_class_factory;
    std::unique_ptr<IMinorClass> m_minor_class; // Pointer to minor class, can point to different minor class types based on major class
};

#endif // CLASSOFDEVICE_H