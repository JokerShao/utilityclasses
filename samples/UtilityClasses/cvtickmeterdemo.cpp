#include <iostream>
#include "opencv2/core.hpp"


int cv_tickmeter_demo()
{
	cv::TickMeter tm;
	tm.start();

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			std::cout << "a";

	tm.stop();
	std::cout << "\nwrite time:" << tm.getTimeMilli() << "ms.\n";
	tm.reset();

	return 0;
}

