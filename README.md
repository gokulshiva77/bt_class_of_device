# bt_class_of_device

This project parses Bluetooth Class of Device (CoD) values and prints the decoded Service Class, Major Device Class, and Minor Device Class.

## Overview

`bt_class_of_device` is a small C++ example that takes a 32-bit Bluetooth Class of Device value and breaks it into its three main components:

- `Service Class` flags
- `Major Device Class`
- `Minor Device Class`

The code uses a class hierarchy and a factory to map major device classes to the appropriate minor class parser.

## Files and Classes

### `main.cpp`
- Entry point for the application.
- Uses a hardcoded CoD value (`0x6A0110` by default).
- Creates a `ClassOfDevice` object and prints the decoded results.

### `ClassOfDevice.h` / `ClassOfDevice.cpp`
- Aggregates the full CoD decoding.
- Holds:
  - `ServiceClass` for service flag decoding.
  - `MajorDeviceClass` for major device class decoding.
  - `MinorClassFactory` and `IMinorClass` for the correct minor class implementation.
- Prints all three decoded results.

### `ServiceClass.h` / `ServiceClass.cpp`
- Parses and decodes Bluetooth service class flags from the CoD value.
- Supported service flags:
  - Limited Discoverable
  - Positioning
  - Networking
  - Rendering
  - Capturing
  - Object Transfer
  - Audio
  - Telephony
  - Information

### `MajorDeviceClass.h` / `MajorDeviceClass.cpp`
- Extracts the major device class field from the CoD.
- Maps the major device class to a human-readable name.
- Available major device classes in this project:
  - Miscellaneous
  - Computer
  - Phone
  - LAN / Network Access Point
  - Audio / Video
  - Peripheral
  - Imaging
  - Wearable
  - Toy
  - Health
  - Uncategorized

### `IMinorClass.h`
- Defines the minor class interface.
- All minor class parsers inherit from `IMinorClass`.
- Contains the helper to extract the minor device class bits.

### `MinorClassFactory.h` / `MinorClassFactory.cpp`
- Factory that selects the correct minor class parser based on the major device class.
- Constructs the appropriate `IMinorClass` implementation for each supported major class.

### `MinorClass/*.h` and `MinorClass/*.cpp`
- Implement minor class parsing for each major device category.
- Supported minor class categories:
  - `ComputerMinorClass`
  - `PhoneMinorClass`
  - `LANMinorClass`
  - `AudioVideoMinorClass`
  - `ImagingMinorClass`
  - `WearableMinorClass`
  - `ToyMinorClass`
  - `HealthMinorClass`

## Bluetooth Class of Device Tables

### Service Class Flags

| Bit Position | Flag Name             | Meaning |
|-------------:|-----------------------|---------|
| 13           | Limited Discoverable  | Limited discoverability mode |
| 15           | Positioning           | Location positioning service |
| 16           | Networking            | Networking service available |
| 17           | Rendering             | Rendering service available |
| 18           | Capturing             | Capturing service available |
| 19           | Object Transfer       | Object transfer service available |
| 20           | Audio                 | Audio service available |
| 21           | Telephony             | Telephony service available |
| 22           | Information           | Information service available |

> Note: The code checks these bits using the `ServiceClassFlags` enum values.

### Major Device Class Values

| Value (hex) | Major Device Class                |
|------------:|-----------------------------------|
| `0x00`      | Miscellaneous                     |
| `0x01`      | Computer                          |
| `0x02`      | Phone                             |
| `0x03`      | LAN / Network Access Point        |
| `0x04`      | Audio / Video                     |
| `0x05`      | Peripheral                        |
| `0x06`      | Imaging                           |
| `0x07`      | Wearable                          |
| `0x08`      | Toy                               |
| `0x09`      | Health                            |
| `0x1F`      | Uncategorized                     |

### Minor Device Class Values

#### Computer Minor Classes

| Value | Minor Class        |
|------:|--------------------|
| `0x00`| Uncategorized       |
| `0x01`| Desktop            |
| `0x02`| Server             |
| `0x03`| Laptop             |
| `0x04`| Handheld           |
| `0x05`| Palm Size          |
| `0x06`| Wearable           |
| `0x07`| Tablet             |

#### Phone Minor Classes

| Value | Minor Class                         |
|------:|-------------------------------------|
| `0x00`| Uncategorized                        |
| `0x01`| Cellular                            |
| `0x02`| Cordless                            |
| `0x03`| Smartphone                          |
| `0x04`| Wired Modem or Voice Gateway        |
| `0x05`| Common ISDN Access                  |

#### LAN / Network Access Point Minor Classes

| Value | Minor Class                |
|------:|-----------------------------|
| `0x00`| Uncategorized                |
| `0x01`| Fully Available             |
| `0x02`| 1% to 17% Utilized          |
| `0x03`| 17% to 33% Utilized         |
| `0x04`| 33% to 50% Utilized         |
| `0x05`| 50% to 67% Utilized         |
| `0x06`| 67% to 83% Utilized         |
| `0x07`| 83% to 99% Utilized         |
| `0x08`| No Service Available        |

#### Audio / Video Minor Classes

| Value | Minor Class                            |
|------:|-----------------------------------------|
| `0x00`| Uncategorized                            |
| `0x01`| Wearable Headset Device                 |
| `0x02`| Hands-free Device                       |
| `0x03`| Microphone                              |
| `0x04`| Loudspeaker                             |
| `0x05`| Headphones                              |
| `0x06`| Portable Audio                          |
| `0x07`| Car Audio                               |
| `0x08`| Set-top Box                             |
| `0x09`| HiFi Audio Device                       |
| `0x0A`| VCR                                     |
| `0x0B`| Video Camera                            |
| `0x0C`| Camcorder                               |
| `0x0D`| Video Monitor                           |
| `0x0E`| Video Display and Loudspeaker           |
| `0x0F`| Video Conferencing                      |

#### Imaging Minor Classes

| Value | Minor Class |
|------:|-------------|
| `0x00`| Display     |
| `0x01`| Camera      |
| `0x02`| Scanner     |
| `0x03`| Printer     |

#### Wearable Minor Classes

| Value | Minor Class  |
|------:|--------------|
| `0x00`| Uncategorized |
| `0x01`| Wristwatch    |
| `0x02`| Pager         |
| `0x03`| Jacket        |
| `0x04`| Helmet        |
| `0x05`| Glasses       |

#### Toy Minor Classes

| Value | Minor Class           |
|------:|------------------------|
| `0x00`| Uncategorized          |
| `0x01`| Robot                  |
| `0x02`| Vehicle                |
| `0x03`| Doll / Action Figure   |
| `0x04`| Controller             |
| `0x05`| Game                   |
| `0x06`| Puzzle                 |
| `0x07`| Toy - Unknown          |

#### Health Minor Classes

| Value | Minor Class                  |
|------:|------------------------------|
| `0x00`| Uncategorized                 |
| `0x01`| Blood Pressure Monitor        |
| `0x02`| Thermometer                   |
| `0x03`| Weighing Scale                |
| `0x04`| Glucose Meter                 |
| `0x05`| Pulse Oximeter                |
| `0x06`| Heart Rate Monitor            |
| `0x07`| Health Data Display           |
| `0x08`| Step Counter                  |
| `0x09`| Body Composition Analyzer     |
| `0x0A`| Peak Flow Monitor             |
| `0x0B`| Medication Monitor            |
| `0x0C`| Knee Prosthesis               |
| `0x0D`| Ankle Prosthesis              |
| `0x0E`| Generic Health Manager        |
| `0x0F`| Personal Mobility Device      |

## Usage

- Build the project with CMake.
- Run the generated executable to print the decoded CoD fields.
- Modify `main.cpp` to test different CoD values as needed.
