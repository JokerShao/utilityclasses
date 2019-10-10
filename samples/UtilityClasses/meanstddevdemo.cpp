#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"

#pragma comment(lib, "opencv_core343d.lib")
#pragma comment(lib, "opencv_imgproc343d.lib")
#pragma comment(lib, "opencv_imgcodecs343d.lib")


std::pair<double, double> cal_mean_stddev(const cv::Mat& gray)
{
	assert(gray.channels() == 1);
	cv::Mat mat_mean, mat_stddev;
	cv::meanStdDev(gray, mat_mean, mat_stddev);
	return std::pair<double, double>(
		mat_mean.at<double>(0, 0),
		mat_stddev.at<double>(0, 0));
}

double cal_mean_gradient(const cv::Mat& gray)
{
	assert(gray.channels() == 1);
	cv::Mat gray64f;
	gray.convertTo(gray64f, CV_64FC1);
	double tmp = 0;
	int rows = gray64f.rows - 1;
	int cols = gray64f.cols - 1;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			double dx = gray64f.at<double>(i, j + 1) - gray64f.at<double>(i, j);
			double dy = gray64f.at<double>(i + 1, j) - gray64f.at<double>(i, j);
			double ds = std::sqrt((dx*dx + dy * dy) / 2);
			tmp += ds;
		}
	}
	// mean gradient
	return tmp / (rows*cols);
}

int image_eval_demo()
{
	cv::Mat img = cv::imread("D:\\DataRepository\\greenscreen\\cup\\2.png");
	cv::Mat gray;
	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
	auto mean_stddev = cal_mean_stddev(gray);
	auto mean_grdient = cal_mean_gradient(gray);
	std::cout << "mean: " << mean_stddev.first << "\nstdDev: " << mean_stddev.second << "\n";
	std::cout << "mean grdient: " << mean_grdient << "\n";
	return 0;
}

