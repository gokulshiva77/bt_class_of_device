#ifndef TOYMINORCLASS_H
#define TOYMINORCLASS_H

#include "IMinorClass.h"

class ToyMinorClass : public IMinorClass
{
public:
    ToyMinorClass(uint32_t cod);
    ~ToyMinorClass();
    std::string getMinorDeviceClass() const override;
private:
    uint32_t m_cod;
    uint8_t m_minor_device_class;
};

#endif // TOYMINORCLASS_H