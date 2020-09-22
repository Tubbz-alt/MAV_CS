#ifndef I2CDEVICE_HPP
#define I2CDEVICE_HPP

#include "device.hpp"
#include <mutex>


class I2CDevice : public Device{
public:

    I2CDevice() = default;

    explicit I2CDevice(uint8_t address,
                       uint16_t length) noexcept;

    bool Open();

    uint32_t Read() override;

    void Write() override;

    virtual ~I2CDevice();

protected:

    const uint8_t address_    = 0x00;
    int file_i2c_             = 0;
    uint16_t length_          = 0;
    unsigned char buffer_[32] = {};
    static std::mutex locker_;

};

#endif // I2CDEVICE_HPP
