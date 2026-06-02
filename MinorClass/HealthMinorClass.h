#ifndef HEALTHMINORCLASS_H
#define HEALTHMINORCLASS_H

#include "IMinorClass.h"

class HealthMinorClass : public IMinorClass
{
public:
    HealthMinorClass(uint32_t cod);
    ~HealthMinorClass();
    std::string getMinorDeviceClass() const override;
private:
    uint32_t m_cod;
    uint8_t m_minor_device_class;
};

#endif // HEALTHMINORCLASS_H