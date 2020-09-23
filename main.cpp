#include <iostream>
#include "Sensor/camera.hpp"
#include "Sensor/thermometer_dht.hpp"
#include <chrono>
using namespace std;

int main()
{
    wiringPiSetup();
    //Camera cam;
    Thermometer_DHT dht(7);

    std::cout << int(dht.Read()) << std::endl;
    //cam.Open();
    //std::this_thread::sleep_for(chrono::milliseconds(100000));
    return 0;
}
