#ifndef THERMOMETER_DHT_HPP
#define THERMOMETER_DHT_HPP

#include "Device/GPIO.hpp"
#include "sensor.hpp"

class Thermometer_DHT : public Sensor{
public:

    enum class DHT{
        DHT11 = 11,
        DHT21 = 21,
        DHT22 = 22
    };

    enum class ErrorCode{
        OK = 0,
        ERROR_CHECKSUM = -1,
        ERROR_TIMEOUT  = -2,
        ERROR_NO_REPLY = -3
    };


    Thermometer_DHT() = default;

    explicit Thermometer_DHT(uint8_t pin,
                             DHT type = DHT::DHT11) noexcept;

    void Read();

    float getHumidity() const noexcept;

    float getTemperatureC() const noexcept;

    float getTemperatureF() const noexcept;

    float getTemperatureK() const noexcept;

protected:

    ErrorCode ReadBackEnd();

    std::unique_ptr<GPIO> source_;

    const DHT type_     = DHT::DHT11;

    float temperatureC_ = 0;

    float humidity_     = 0;
};

#endif // THERMOMETER_DHT_HPP
