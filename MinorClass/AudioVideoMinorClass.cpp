#include "AudioVideoMinorClass.h"

#include <map>

std::map<uint8_t, std::string> cod_minor_device_class_map_audio_video = {
    {0x00, "Uncategorized"},
    {0x01, "Wearable Headset Device"},
    {0x02, "Hands-free Device"},
    {0x03, "Microphone"},
    {0x04, "Loudspeaker"},
    {0x05, "Headphones"},
    {0x06, "Portable Audio"},
    {0x07, "Car Audio"},
    {0x08, "Set-top Box"},
    {0x09, "HiFi Audio Device"},
    {0x0A, "VCR"},
    {0x0B, "Video Camera"},
    {0x0C, "Camcorder"},
    {0x0D, "Video Monitor"},
    {0x0E, "Video Display and Loudspeaker"},
    {0x0F, "Video Conferencing"}
};

AudioVideoMinorClass::AudioVideoMinorClass(uint32_t cod):
    m_cod(cod),
    m_minor_device_class(getMinorDeviceClassCode(cod))
{
    
}

AudioVideoMinorClass::~AudioVideoMinorClass()
{
    
}

std::string AudioVideoMinorClass::getMinorDeviceClass() const 
{
    auto it = cod_minor_device_class_map_audio_video.find(m_minor_device_class);
    if (it != cod_minor_device_class_map_audio_video.end()) {
        return it->second;
    }
    return "Reserved";
}
