#ifndef GPIODEVICE_HPP
#define GPIODEVICE_HPP

#include <stdint.h>
#include "wiringPi.h"


class GPIO {
public:

    GPIO() = default;

    GPIO(uint8_t pin) noexcept;

    void DigitalWrite(int level) const;

    int DigitalRead() const;

    void PinMode(int mode);

    uint8_t getPin() const noexcept;

    unsigned long pulseInLength(bool state, unsigned long timeout = 1'000'000L);

    enum class ErrorCode{
        OK = 0,
        ERROR_CHECKSUM = -1,
        ERROR_TIMEOUT  = -2,
        ERROR_NO_REPLY = -3
    };

protected:

    const uint8_t pin_ = 0;

};

#endif // GPIODEVICE_HPP
