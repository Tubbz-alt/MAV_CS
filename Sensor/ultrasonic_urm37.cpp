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

    auto time = echo_->pulseInLength(LOW, 45000);
    if(time == 0)
        return GPIO::ErrorCode::ERROR_TIMEOUT;

    tmp_ = time / 50;

    return GPIO::ErrorCode::OK;
}

void UltraSonic_URM37::TryToCollectData(){
    while(int(ReadBackEnd()) || tmp_ < 2){delayMicroseconds(1);}
}

void UltraSonic_URM37::Read(){
    bool verify_f = false;
    int verify_data[3] = {0, 0, 0};
    while(!verify_f){
        for(uint8_t i = 0; i < 3; ++i){
            TryToCollectData();
            verify_data[i] = static_cast<int>(tmp_);
            tmp_ = 0;
        }
        verify_f = VerifiedData(verify_data);
    }
     //while(int(ReadBackEnd()) || distance_ == 0) {delayMicroseconds(100);}
}

bool UltraSonic_URM37::VerifiedData(const int* data)  noexcept{
    int sum = (data[0] + data[1] + data[2]) / 3;
    for(uint8_t i = 0; i < 3; ++i ){
        if(abs(sum - data[i]) > sum * 0.1 + 1)
            return false;
    }
    distance_ = static_cast<uint32_t>(sum);
    return true;
}
