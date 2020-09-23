#ifndef GPIODEVICE_HPP
#define GPIODEVICE_HPP

#include <stdint.h>
#include "wiringPi.h"


class GPIO {
public:

    GPIO() = default;

    GPIO(uint8_t pin) noexcept;

    void DigitalWritre(int level) const;

    int DigitalRead() const;

    void PinMode(int mode);

    uint8_t getPin() const noexcept;

    unsigned long pulseInLength(bool state, unsigned long timeout = 1'000'000L);


protected:

    const uint8_t pin_ = 0;

};

#endif // GPIODEVICE_HPP
