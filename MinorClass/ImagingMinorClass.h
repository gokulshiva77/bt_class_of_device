#ifndef IMAGINGMINORCLASS_H
#define IMAGINGMINORCLASS_H

#include "IMinorClass.h"

class ImagingMinorClass : public IMinorClass
{
public:
    ImagingMinorClass(uint32_t cod);
    ~ImagingMinorClass();
    std::string getMinorDeviceClass() const override;
private:
    uint32_t m_cod;
    uint8_t m_minor_device_class;
};
#endif // IMAGINGMINORCLASS_H