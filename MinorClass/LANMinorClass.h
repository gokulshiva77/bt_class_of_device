#ifndef LANMINORCLASS_H
#define LANMINORCLASS_H

#include "IMinorClass.h"

class LANMinorClass : public IMinorClass
{
public:
    LANMinorClass(uint32_t cod);
    ~LANMinorClass();
    std::string getMinorDeviceClass() const override;
private:
    uint32_t m_cod;
    uint8_t m_minor_device_class;
};

#endif // LANMINORCLASS_H