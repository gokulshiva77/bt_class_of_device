#ifndef PhoneMinorClass_H
#define PhoneMinorClass_H

#include "IMinorClass.h"

class PhoneMinorClass : public IMinorClass
{
public:
    PhoneMinorClass(uint32_t cod);
    ~PhoneMinorClass();

    std::string getMinorDeviceClass() const override;
private:
    uint32_t m_cod;
    uint8_t m_minor_device_class;
};


#endif // PhoneMinorClass_H