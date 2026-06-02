cmake_minimum_required(VERSION 3.10.0)
project(BTCOD VERSION 0.1.0 LANGUAGES C CXX)

add_executable(BTCOD main.cpp
                     ClassOfDevice.cpp
                     ServiceClass.cpp
                     MajorDeviceClass.cpp
                     MinorClass/ComputerMinorClass.cpp
                     MinorClass/PhoneMinorClass.cpp
                     MinorClass/AudioVideoMinorClass.cpp
                     MinorClass/PeripheralMinorClass.cpp
                     MinorClass/ImagingMinorClass.cpp
                     MinorClass/LANMinorClass.cpp
                     MinorClass/WearableMinorClass.cpp
                     MinorClass/ToyMinorClass.cpp
                     MinorClass/HealthMinorClass.cpp
                     MinorClass/MinorClassFactory.cpp
                     )

target_include_directories(BTCOD PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/MinorClass")