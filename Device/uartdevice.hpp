#ifndef UARTDEVICE_HPP
#define UARTDEVICE_HPP

#include "device.hpp"

class UARTDevice : public Device{
public:

    UARTDevice() = default;

    UARTDevice(uint32_t bods) noexcept;

    uint32_t Read() override{}

    void Write() override{}

protected:

    const uint32_t bods_ = 0;
};

#endif // UARTDEVICE_HPP
