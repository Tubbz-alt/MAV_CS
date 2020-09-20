#include "i2cdevice.hpp"
#include "linux/i2c-dev.h"
#include "sys/ioctl.h"
#include "fcntl.h"
#include "unistd.h"

I2CDevice::I2CDevice(uint8_t address,
                     uint16_t length) noexcept :
    address_(address),
    length_(length){}

I2CDevice::~I2CDevice(){
    if(file_i2c_)
        close(file_i2c_);
}

bool I2CDevice::open(){
    char* filename = (char*)"/dev/i2c-1";
    file_i2c_ = open(filename, O_RDWR);
    if(file_i2c_ < 0)
        return false;
    if(ioctl(file_i2c_, I2C_SLAVE, address_) < 0)
        return false;
    return true;
}

uint32_t I2CDevice::read(){
    if(read(file_i2c_, buffer_, length_) != length_)
        return 0;
}

void I2CDevice::write(){
    int len = 2;
    if(write(file_i2c_, buffer_ + 16, len) != len)
        return;
}
