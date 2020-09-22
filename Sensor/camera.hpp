#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "sensor.hpp"
#include "opencv2/core.hpp"
#include "opencv2/videoio.hpp"

#include <thread>

class Camera : public Sensor{
public:

    Camera() = default;

    ~Camera();

    bool Open();


protected:

    void ImageProccessing();

    bool running_ = false;
    cv::VideoCapture cap_;
    std::thread vision_thread_;

};

#endif // CAMERA_HPP
