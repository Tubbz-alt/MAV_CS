#include "GPIO.hpp"
#include <chrono>

GPIO::GPIO(uint8_t pin) noexcept : pin_(pin) {}


uint8_t GPIO::getPin() const noexcept{
    return pin_;
}

unsigned long GPIO::pulseInLength(bool state, unsigned long timeout){
    auto start = std::chrono::steady_clock::now();

    while(digitalRead(pin_) == state){
        if(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count() > timeout)
            return 0;
    }
    return static_cast<unsigned long>(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count());
}

void GPIO::PinMode(int mode){
    pinMode(pin_, mode);
}

int GPIO::DigitalRead() const{
    return digitalRead(pin_);
}

void GPIO::DigitalWritre(int level) const{
    digitalWrite(pin_, level);
}
