#include "lib_cxx/src/bridge.rs.h"
#include "lib_cxx/cpp/ftheta.h"
#include <opencv2/opencv.hpp>

int main(){
    say_hello();
    cv::Mat image(300, 300, CV_8UC3, cv::Scalar(255, 255, 255));

    // Define circle parameters
    cv::Point center(150, 150); // center at (150,150)
    int radius = 80;
    cv::Scalar color(0, 0, 0); // black in BGR
    int thickness = 2; // 2 px border thickness (-1 means filled)

    // Draw the circle
    cv::circle(image, center, radius, color, thickness);
    cv::Mat image2(3, 3, CV_8UC3, cv::Scalar(0, 255, 105));
    ftheta::initUndistort(image2);
    return 0;
}