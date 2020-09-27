#ifndef ULTRASSONIC_URM37_HPP
#define ULTRASSONIC_URM37_HPP
#include "Device/GPIO.hpp"
#include "sensor.hpp"

class UltraSonic_URM37 : public Sensor{
public:

    UltraSonic_URM37() = default;

    explicit UltraSonic_URM37(uint8_t pin_echo,
                     uint8_t pin_trig) noexcept;

    uint32_t GetDistance() const noexcept;

    void Read();

protected:

    void Setup();

    bool VerifiedData(const uint32_t* data)  noexcept{}

    GPIO::ErrorCode ReadBackEnd();

    std::unique_ptr<GPIO> echo_ = nullptr;
    std::unique_ptr<GPIO> trig_ = nullptr;

    uint32_t distance_ = 0;
};

#endif // ULTRASSONIC_URM37_HPP
