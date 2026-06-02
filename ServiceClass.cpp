#include "ServiceClass.h"

ServiceClass::ServiceClass(uint32_t cod)
{
    m_cod = cod;
    m_service_class = cod; // Extract service class (bit 13-23)
}

ServiceClass::~ServiceClass()
{
    
}

std::string ServiceClass::getServiceClass() const 
{
    std::string output = "";
    if(m_service_class & (1 << LIMITED_DISCOVERABLE_SC))
    {
        output += "Limited Discoverable";
        output += ", ";
    }
    if(m_service_class & (1 << POSITIONING_SC))
    {
        output += "Positioning";
        output += ", ";
    }
    if(m_service_class & (1 << NETWORKING_SC))
    {
        output += "Networking";
        output += ", ";
    }
    if(m_service_class & (1 << RENDERING_SC))
    {
        output += "Rendering";
        output += ", ";
    }
    if(m_service_class & (1 << CAPTURING_SC))
    {
        output += "Capturing";
        output += ", ";
    }
    if(m_service_class & (1 << OBJECT_TRANSFER_SC))
    {
        output += "Object Transfer";
        output += ", ";
    }
    if(m_service_class & (1 << AUDIO_SC))
    {
        output += "Audio";
        output += ", ";
    }
    if(m_service_class & (1 << TELEPHONY_SC))
    {
        output += "Telephony";
        output += ", ";
    }
    if(m_service_class & (1 << INFORMATION_SC))
    {
        output += "Information";
        output += ", ";
    }
    return output;
}

void ServiceClass::addComma(std::string &output)
{
    if (!output.empty())
    {
        output += ", ";
    }
}