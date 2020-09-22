#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <stdint.h>

class Device{

public:
    Device() = default;

    virtual ~Device();

protected:

    virtual uint32_t Read() = 0;

    virtual void Write() = 0;
};

#endif // DEVICE_HPP
