#ifndef AUDIOVIDEOMINORCLASS_H
#define AUDIOVIDEOMINORCLASS_H

#include "IMinorClass.h"

class AudioVideoMinorClass : public IMinorClass
{
public:
    AudioVideoMinorClass(uint32_t cod);
    ~AudioVideoMinorClass();
    std::string getMinorDeviceClass() const override;
private:
    uint32_t m_cod;
    uint8_t m_minor_device_class;
};
#endif // AUDIOVIDEOMINORCLASS_H