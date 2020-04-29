#include "numerical2string.h"
#include <iostream>


int ftos_demo()
{
	float f1 = 123.456f;
	double d1 = 123.000;
	long double ld1 = 123.0001110001;

	auto str_f1 = ftos<float>("%.3f", f1);
	auto str_d1 = ftos<double>("%.4f", d1);
	auto str_ld1 = ftos<long double>("%.6f", ld1);

	std::cout << "f1: " << str_f1 << "\n";
	std::cout << "d1: " << str_d1 << "\n";
	std::cout << "ld1: " << str_ld1 << "\n";

	return 0;
}

