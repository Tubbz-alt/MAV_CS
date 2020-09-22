#include "camera.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

Camera::~Camera(){
    running_ = false;
    vision_thread_.join();
}

bool Camera::Open(){
    if(!cap_.open(0))
        return false;
    vision_thread_ = std::thread(&Camera::ImageProccessing, this);

    running_ = true;

    return true;
}

void Camera::ImageProccessing(){

    cv::Mat original_frame,
            gray_frame,
            canny_frame;

    cv::namedWindow("Camera");

    while(running_){

        cap_ >> original_frame;
        if(original_frame.empty())
            break;
        cv::cvtColor(original_frame, gray_frame, cv::COLOR_BGR2GRAY);
        cv::Canny(gray_frame, canny_frame, 10, 100);
        cv::imshow("Camera", canny_frame);
        cv::waitKey(100);

    }
}
