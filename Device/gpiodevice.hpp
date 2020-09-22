#ifndef GPIODEVICE_HPP
#define GPIODEVICE_HPP

#include "device.hpp"
#include "wiringPi.h"

class GPIODevice : public Device{
public:

    GPIODevice() = default;

    GPIODevice(uint8_t pin) noexcept;


protected:

    const uint8_t pin_ = 0;
};

#endif // GPIODEVICE_HPP
