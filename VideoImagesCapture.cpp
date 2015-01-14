// VideoImages.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	VideoCapture cap("video.avi");
	if(!cap.isOpened())  // check if we succeeded
		return -1;
	long totalFrameNumber = cap.get(CV_CAP_PROP_FRAME_COUNT);
	namedWindow("edges",1);

	for(int i=0;i<totalFrameNumber;i++)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		
		imshow("edges", frame);

		stringstream ss;
		string str;
		ss<<i;
		ss >> str;
		string  name = "image/image" + str +".jpg";


		imwrite(name,frame);
		if(waitKey(30) >= 0) break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}

