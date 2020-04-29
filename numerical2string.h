#pragma once

#include <string>


template<typename T>
std::string ftos(const std::string& format, const T& numerical)
{
	char str[100];
	sprintf_s(str, sizeof(str), format.c_str(), numerical);
	return std::string(str);
}

