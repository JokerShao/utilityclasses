#include <iostream>
#include <thread>
#include "opencv2/highgui.hpp"

#pragma comment(lib, "opencv_core343d.lib")
#pragma comment(lib, "opencv_highgui343d.lib")


//void slide_bar(int val, void*) {
//	cv::Mat display_pic;
//	cv::blur(pic0, display_pic, cv::Size(val, val));
//	cv::imshow("滑动窗口", display_pic);
//}

int trackbar_demo()
{
	cv::namedWindow("trackbar", 0);

	int value = 15;
	cv::createTrackbar("value", "trackbar", &value, 20);
	cv::setTrackbarMin("value", "trackbar", 10);

	while (true)
	{
		std::cout << "value: " << value << "\n";
		cv::waitKey(10);
	}

	return 0;
}

