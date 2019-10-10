#include <iostream>


template<typename T>
std::string ftos(const std::string& format, const T numerical)
{
	char str[100];
	sprintf_s(str, sizeof(str), format.c_str(), numerical);
	return std::string(str);
}

int ftos_demo()
{
	float f1 = 123.456f;
	double d1 = 123.000;
	long double ld1 = 123.0001110001;

	auto str_f1 = ftos<float>("%.3f", f1);
	auto str_d1 = ftos<double>("%.4f", d1);
	auto str_ld1 = ftos<long double>("%.6f", ld1);

	std::cout << "f1: " << str_f1.c_str() << "\n";
	std::cout << "d1: " << str_d1.c_str() << "\n";
	std::cout << "ld1: " << str_ld1.c_str() << "\n";

	return 0;
}

