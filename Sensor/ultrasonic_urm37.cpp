#include "ultrassonic_urm37.hpp"
#include  <iostream>

UltraSonic_URM37::UltraSonic_URM37(uint8_t pin_echo,
                                   uint8_t pin_trig) noexcept :
    echo_(std::make_unique<GPIO>(pin_echo)),
    trig_(std::make_unique<GPIO>(pin_trig)){
    Setup();
}


void UltraSonic_URM37::Setup(){
    trig_->PinMode(OUTPUT);
    trig_->DigitalWrite(HIGH);
    echo_->PinMode(INPUT);
    delay(500);
}

uint32_t UltraSonic_URM37::GetDistance() const noexcept {return distance_;}

GPIO::ErrorCode UltraSonic_URM37::ReadBackEnd(){

    trig_->DigitalWrite(LOW);
    trig_->DigitalWrite(HIGH);

    auto time = echo_->pulseInLength(LOW, 50000);
    if(time == 0)
        return GPIO::ErrorCode::ERROR_TIMEOUT;

    distance_ = time / 50;

    return GPIO::ErrorCode::OK;
}

void UltraSonic_URM37::Read(){
     while(int(ReadBackEnd()) || distance_ == 0) {delay(1);}
}
