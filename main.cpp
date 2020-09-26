#include <iostream>
#include "Sensor/camera.hpp"
#include "Sensor/thermometer_dht.hpp"
#include <chrono>
using namespace std;

int main()
{
    wiringPiSetup();

    //Camera cam;
    Thermometer_DHT dht(0, Thermometer_DHT::DHT::DHT11);
    auto start = std::chrono::steady_clock::now();
    dht.Read();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count() <<std::endl;
    std::cout << dht.getHumidity() << std::endl;
    std::cout << dht.getTemperatureC() << std::endl;
    //cam.Open();
    //std::this_thread::sleep_for(chrono::milliseconds(100000));
    return 0;
}
