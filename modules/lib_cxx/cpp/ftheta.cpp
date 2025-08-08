#include "ftheta.h"

#include <iostream>

using namespace cv;
using namespace std;

void initUndistort(InputArray img){
    Mat m = img.getMat();
    cout << "abc" << m.channels() << endl;
}