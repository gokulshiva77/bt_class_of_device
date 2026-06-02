#ifndef SERVICECLASS_H
#define SERVICECLASS_H

#include <cstdint>
#include <string>

enum ServiceClassFlags {
    LIMITED_DISCOVERABLE_SC = 13,
    RESERVED_SC1,
    RESERVED_SC2,
    POSITIONING_SC,
    NETWORKING_SC,
    RENDERING_SC,
    CAPTURING_SC,
    OBJECT_TRANSFER_SC,
    AUDIO_SC,
    TELEPHONY_SC,
    INFORMATION_SC,
};
class ServiceClass
{
public:
    ServiceClass(uint32_t cod);
    ~ServiceClass();

    std::string getServiceClass() const;
private:
    void addComma(std::string &output);
private:
    uint32_t m_cod;
    uint32_t m_service_class;
};

#endif // SERVICECLASS_H