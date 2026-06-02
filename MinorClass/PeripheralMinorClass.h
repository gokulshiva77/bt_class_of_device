#ifndef PERIPHERALMINORCLASS_H
#define PERIPHERALMINORCLASS_H

#include "IMinorClass.h"

class PeripheralMinorClass : public IMinorClass
{
public:
    PeripheralMinorClass(uint32_t cod);
    ~PeripheralMinorClass();
    std::string getMinorDeviceClass() const override;
private:
    uint32_t m_cod;
    uint8_t m_minor_device_class;
    uint8_t m_minor_sub_device_class;
};

#endif // PERIPHERALMINORCLASS_H