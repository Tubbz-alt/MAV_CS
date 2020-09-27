#include <iostream>
#include "Sensor/camera.hpp"
#include "Sensor/thermometer_dht.hpp"
#include "Sensor/ultrassonic_urm37.hpp"
#include <chrono>
using namespace std;

int main()
{
    wiringPiSetup();

    //amera cam;
    Thermometer_DHT dht(0, Thermometer_DHT::DHT::DHT11);
    auto start = std::chrono::steady_clock::now();
    dht.Read();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count() <<std::endl;
    std::cout << dht.getHumidity() << std::endl;
    std::cout << dht.getTemperatureC() << std::endl;
    UltraSonic_URM37 us(26, 24);
    while(true){
    us.Read();
    std::cout << us.GetDistance() << std::endl;
    }
   // cam.Open();
   // std::this_thread::sleep_for(chrono::milliseconds(100000));
    return 0;
}
