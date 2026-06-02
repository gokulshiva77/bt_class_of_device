#ifndef WEARABLEMINORCLASS_H
#define WEARABLEMINORCLASS_H

#include "IMinorClass.h"

class WearableMinorClass : public IMinorClass
{
public:
    WearableMinorClass(uint32_t cod);
    ~WearableMinorClass();
    std::string getMinorDeviceClass() const override;
private:
    uint32_t m_cod;
    uint8_t m_minor_device_class;
};

#endif // WEARABLEMINORCLASS_H