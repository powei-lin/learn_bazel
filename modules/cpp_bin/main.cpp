#include <opencv2/opencv.hpp>

#include "lib_cxx/cpp/ftheta.h"
#include "lib_cxx/src/bridge.rs.h"

using namespace cv;

int main() {
  say_hello();
  cv::Mat image(300, 300, CV_8UC3, cv::Scalar(255, 255, 255));

  // Define circle parameters
  cv::Point center(150, 150);  // center at (150,150)
  int radius = 80;
  cv::Scalar color(0, 0, 0);  // black in BGR
  int thickness = 2;          // 2 px border thickness (-1 means filled)

  // Draw the circle
  cv::circle(image, center, radius, color, thickness);
  cv::Mat image2(300, 200, CV_8UC3, cv::Scalar(0, 255, 105));
  cv::Mat mapx;
  ftheta::initUndistort(image2, mapx);
  cv::imwrite("aaa.jpg", image2);
  cv::imwrite("aaa1.jpg", mapx);

  cv::Mat camera_params = (Mat_<float>(3, 3) << 381.8942, 0, 510.4261, 0, 381.8942, 514.2049, 0, 0, 1);
  cv::Mat distortion_params = (Mat_<float>(6, 1) << 1, -0.013526307651937557, 0.05299230893435198, -0.07478361618623298,
                               0.05271454601615845, -0.015815671668607537);
  cv::Mat distortion_params_fish =
      (Mat_<float>(4, 1) << 0.006320706378871676, -0.004079516257421035, 0.0012512437550804651, -0.0005132303126873521);
  cv::Mat mapx_f, mapy_f;
  cv::fisheye::initUndistortRectifyMap(camera_params, distortion_params_fish, cv::noArray(), camera_params,
                                       cv::Size(1024, 1024), CV_32FC1, mapx_f, mapy_f);
  cv::Mat mapx_f1, mapy_f1;
  ftheta::initUndistortRectifyMap(camera_params, distortion_params_fish, cv::noArray(), camera_params,
                                  cv::Size(1024, 1024), CV_32FC1, mapx_f1, mapy_f1);
  Mat img_tum = cv::imread("tum.png");
  Mat undistort_img;
  cv::remap(img_tum, undistort_img, mapx_f, mapy_f, cv::INTER_LINEAR);

  cv::imwrite("undistorted.jpg", undistort_img);
  return 0;
}