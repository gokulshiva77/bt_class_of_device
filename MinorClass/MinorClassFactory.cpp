#include "MinorClassFactory.h"

#include "ComputerMinorClass.h"
#include "PhoneMinorClass.h"
#include "LANMinorClass.h"
#include "AudioVideoMinorClass.h"
#include "ImagingMinorClass.h"
#include "WearableMinorClass.h"
#include "ToyMinorClass.h"
#include "HealthMinorClass.h"

MinorClassFactory::MinorClassFactory()
{
    registry[MajorDeviceClassType::Computer] = [](uint32_t cod) { return std::make_unique<ComputerMinorClass>(cod); };
    registry[MajorDeviceClassType::Phone] = [](uint32_t cod) { return std::make_unique<PhoneMinorClass>(cod); };
    registry[MajorDeviceClassType::LAN_Network_Access_Point] = [](uint32_t cod) { return std::make_unique<LANMinorClass>(cod); };
    registry[MajorDeviceClassType::Audio_Video] = [](uint32_t cod) { return std::make_unique<AudioVideoMinorClass>(cod); };
    registry[MajorDeviceClassType::Imaging] = [](uint32_t cod) { return std::make_unique<ImagingMinorClass>(cod); };
    registry[MajorDeviceClassType::Wearable] = [](uint32_t cod) { return std::make_unique<WearableMinorClass>(cod); };
    registry[MajorDeviceClassType::Toy] = [](uint32_t cod) { return std::make_unique<ToyMinorClass>(cod); };
    registry[MajorDeviceClassType::Health] = [](uint32_t cod) { return std::make_unique<HealthMinorClass>(cod); };

}

MinorClassFactory::~MinorClassFactory()
{
    
}

std::unique_ptr<IMinorClass> MinorClassFactory::createMinorClass(MajorDeviceClassType majorClass, uint32_t cod)
{
    std::unique_ptr<IMinorClass> minorClass = nullptr;
    auto it = registry.find(majorClass);
    if (it != registry.end()) {
        minorClass = it->second(cod); // Pass the provided COD
    }
    return minorClass;
}
