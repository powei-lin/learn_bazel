#pragma once

#include <opencv2/core/mat.hpp>

namespace ftheta {
void initUndistort(cv::InputArray img);
void initUndistortRectifyMap(cv::InputArray cameraMatrix,
                             cv::InputArray distCoeffs, cv::InputArray R,
                             cv::InputArray newCameraMatrix, cv::Size size,
                             int m1type, cv::OutputArray map1,
                             cv::OutputArray map2);
void projectPoints(cv::InputArray objectPoints, cv::InputArray rvec,
                   cv::InputArray tvec, cv::InputArray cameraMatrix,
                   cv::InputArray distCoeffs, cv::OutputArray imagePoints);

} // namespace ftheta