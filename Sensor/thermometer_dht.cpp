#include "thermometer_dht.hpp"

Thermometer_DHT::Thermometer_DHT(uint8_t pin,
                                 Thermometer_DHT::DHT type) noexcept :
    source_(std::make_unique<GPIO>(pin)),
    type_(type) {}

float Thermometer_DHT::getHumidity() const noexcept{
    return humidity_;
}

float Thermometer_DHT::getTemperatureC() const noexcept{
    return temperatureC_;
}

float Thermometer_DHT::getTemperatureF() const noexcept{
    return temperatureC_ * 1.8f + 32.f;
}

float Thermometer_DHT::getTemperatureK() const noexcept {
    return temperatureC_ + 273.15f;
}

GPIO::ErrorCode Thermometer_DHT::ReadBackEnd(){
    uint8_t data[5] = {0, 0, 0, 0, 0};
    uint8_t databit;
    uint8_t checkSum;
    source_->PinMode(OUTPUT);
    source_->DigitalWrite(LOW);
    delay(18);
    source_->PinMode(INPUT);
    if(source_->pulseInLength(HIGH, 60) == 0)
        return GPIO::ErrorCode::ERROR_NO_REPLY;

    if(source_->pulseInLength(LOW, 120) == 0)
        return GPIO::ErrorCode::ERROR_NO_REPLY;

    if(source_->pulseInLength(HIGH, 120) == 0)
        return GPIO::ErrorCode::ERROR_NO_REPLY;

    for(uint8_t i = 0; i < 40; i++){
        source_->pulseInLength(LOW, 70);
        databit = source_->pulseInLength(HIGH, 120);
        if(databit){
            data[i / 8] <<= 1;
            data[i / 8] += databit > 45 ? 1 : 0;
        }
        else
            return GPIO::ErrorCode::ERROR_TIMEOUT;
    }

    checkSum = data[0] + data[1] + data[2] + data[3];
    if(data[4] != checkSum)
        return GPIO::ErrorCode::ERROR_CHECKSUM;

    if(type_ == Thermometer_DHT::DHT::DHT11){
        humidity_ = data[0];
        temperatureC_ = data[3] & 0x80 ? (data[2] + (1 - (data[3] & 0x7F) * 0.1f)) * -1 : (data[2] + (data[3] & 0x7F) * 0.1f);
    }
    else if(type_ == Thermometer_DHT::DHT::DHT21 || type_ == Thermometer_DHT::DHT::DHT22){
        humidity_ = ((data[0] << 8) + data[1]) * 0.1f;
        temperatureC_ = (((data[2] & 0x7F) << 8) + data[3]) * (data[2] & 0x80 ? -0.1f : 0.1f);
    }
    return GPIO::ErrorCode::OK;
}

void Thermometer_DHT::Read(){
    while(int(ReadBackEnd())) {}
}
