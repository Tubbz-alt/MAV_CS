#include "GPIO.hpp"

GPIO::GPIO(uint8_t pin) noexcept : pin_(pin) {}


uint8_t GPIO::getPin() const noexcept{
    return pin_;
}

unsigned long GPIO::pulseInLength(bool state, unsigned long timeout){
    auto start = micros();

    while(digitalRead(pin_) == state){
        if(micros() - start > timeout)
            return 0;
    }
    return micros() - start;
}

void GPIO::PinMode(int mode){
    pinMode(pin_, mode);
}

int GPIO::DigitalRead() const{
    return digitalRead(pin_);
}

void GPIO::DigitalWrite(int level) const{
    digitalWrite(pin_, level);
}
