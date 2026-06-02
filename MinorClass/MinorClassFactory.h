#ifndef MINORCLASSFACTORY_H
#define MINORCLASSFACTORY_H

#include <functional>
#include <unordered_map>
#include <memory>


#include "IMinorClass.h"
#include "MajorDeviceClass.h"

class MinorClassFactory
{
public:
    MinorClassFactory();
    ~MinorClassFactory();
    std::unique_ptr<IMinorClass> createMinorClass(MajorDeviceClassType majorClass, uint32_t cod);
private:
    std::unordered_map<MajorDeviceClassType, std::function<std::unique_ptr<IMinorClass>(uint32_t)>> registry; // Map of major device class type to minor class factory function
};

#endif // MINORCLASSFACTORY_H