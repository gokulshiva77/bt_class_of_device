#ifndef COMPUTERMINORCLASS_H
#define COMPUTERMINORCLASS_H

#include <cstdint>
#include <string>
#include "IMinorClass.h"

class ComputerMinorClass : public IMinorClass
{
public:
    ComputerMinorClass(uint32_t cod);
    ~ComputerMinorClass();
    std::string getMinorDeviceClass() const override;
private:
    uint32_t m_cod;
    uint8_t m_minor_device_class;
};


#endif // COMPUTERMINORCLASS_H