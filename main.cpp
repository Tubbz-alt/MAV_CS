#include <iostream>
#include "Sensor/camera.hpp"
#include <chrono>
using namespace std;

int main()
{
    Camera cam;
    cam.Open();
    std::this_thread::sleep_for(chrono::milliseconds(100000));
    return 0;
}
