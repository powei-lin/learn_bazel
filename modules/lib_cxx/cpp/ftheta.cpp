#include "ftheta.h"
#include "lib_cxx/src/bridge.rs.h"
#include <iostream>

using namespace cv;
using namespace std;

namespace ftheta {
void initUndistort(InputArray img) {
  cv::Mat mat = img.getMat();
  if (mat.type() != CV_32F) {
    mat.convertTo(mat, CV_32F);
  }
  std::vector<float> out;
  out.assign((float *)mat.datastart, (float *)mat.dataend);
  print_vec(out);
  // cout << "abc " << m.channels() << endl;
}
void initUndistortRectifyMap(InputArray _cameraMatrix, InputArray _distCoeffs,
                             InputArray _matR, InputArray _newCameraMatrix,
                             Size size, int m1type, OutputArray _map1,
                             OutputArray _map2) {

  Mat cameraMatrix = _cameraMatrix.getMat(), distCoeffs = _distCoeffs.getMat();
  Mat matR = _matR.getMat(), newCameraMatrix = _newCameraMatrix.getMat();

  if (m1type <= 0)
    m1type = CV_16SC2;
  CV_Assert(m1type == CV_16SC2 || m1type == CV_32FC1 || m1type == CV_32FC2);
  _map1.create(size, m1type);
  Mat map1 = _map1.getMat(), map2;
  if (m1type != CV_32FC2) {
    _map2.create(size, m1type == CV_16SC2 ? CV_16UC1 : CV_32FC1);
    map2 = _map2.getMat();
  } else
    _map2.release();

  Mat_<double> R = Mat_<double>::eye(3, 3);
  Mat_<double> A = Mat_<double>(cameraMatrix), Ar;
}
void projectPoints(cv::InputArray _objectPoints, cv::InputArray rvec,
                   cv::InputArray tvec, cv::InputArray cameraMatrix,
                   cv::InputArray distCoeffs, cv::OutputArray imagePoints) {
  Mat _m, objectPoints = _objectPoints.getMat();
  // Mat dpdr, dpdt, dpdc, dpdf, dpdk, dpdo;

  // int i, j;
  // double R[9], dRdr[27], t[3], a[9],
  //     k[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, fx, fy, cx, cy;
  // Matx33d matTilt = Matx33d::eye();
  // Matx33d dMatTiltdTauX(0, 0, 0, 0, 0, 0, 0, -1, 0);
  // Matx33d dMatTiltdTauY(0, 0, 0, 0, 0, 0, 1, 0, 0);
  // Mat matR(3, 3, CV_64F, R), _dRdr(3, 9, CV_64F, dRdr);
  // double *dpdr_p = 0, *dpdt_p = 0, *dpdk_p = 0, *dpdf_p = 0, *dpdc_p = 0;
  // double *dpdo_p = 0;
  // int dpdr_step = 0, dpdt_step = 0, dpdk_step = 0, dpdf_step = 0, dpdc_step =
  // 0; int dpdo_step = 0;

  // int objpt_depth = objectPoints.depth();
  // int objpt_cn = objectPoints.channels();
  // int total = (int)(objectPoints.total() * objectPoints.channels());
  // int count = total / 3;
}
} // namespace ftheta