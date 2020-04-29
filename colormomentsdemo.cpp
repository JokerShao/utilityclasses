#if 0

/** formula see https://blog.csdn.net/Blateyang/article/details/70499972 */
#include <iostream>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

#pragma comment(lib, "opencv_core343d.lib")
#pragma comment(lib, "opencv_highgui343d.lib")


double calc3orderMom(cv::Mat& channel) //计算三阶矩
{
	double m = cv::mean(channel)[0];    //计算单通道图像的均值
	double mom = 0.0;

	uchar* p = nullptr;
	for (int i = 0; i < channel.rows; i++) //计算立方和
	{
		p = channel.ptr<uchar>(i);
		for (int j = 0; j < channel.cols; j++)
			mom += pow((p[j] - m), 3);
	}
	return cv::cubeRoot((float)(mom / (channel.rows * channel.cols)));    //求均值的立方根
}

// 计算9个颜色矩：3个通道的1、2、3阶矩
void colorMom(const cv::Mat& img, double* Mom)
{
	assert(img.channels() == 3);
	cv::Mat tmp_m, tmp_sd;
	std::vector<cv::Mat> channels(3);
	cv::split(img, channels);

	for (int idx = 0; idx < 3; idx++)
	{
		cv::meanStdDev(channels[idx], tmp_m, tmp_sd);
		Mom[idx] = tmp_m.at<double>(0, 0);
		Mom[idx + 3] = tmp_sd.at<double>(0, 0);
		Mom[idx + 6] = calc3orderMom(channels[idx]);
	}
}


int color_moments_demo()
{
	cv::Mat src1 = cv::imread("img1.jpg");
	cv::Mat src2 = cv::imread("img2.jpg");
	if (src1.data == NULL || src2.data == NULL)
		std::cout << "image load failed!";

	double Mom1[9], Mom2[9];
	colorMom(src1, Mom1);
	colorMom(src2, Mom2);

	std::cout << "Color moments:";
	for (int i = 0; i < 9; i++)//输出颜色矩
		std::cout << Mom1[i] << " ";
	std::cout << std::endl;
	std::cout << "Color moments:";
	for (int i = 0; i < 9; i++)//输出颜色矩
		std::cout << Mom2[i] << " ";
	std::cout << std::endl;

	return 0;
}

#endif

