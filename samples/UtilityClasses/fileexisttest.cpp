#include <iostream>
#include <corecrt_io.h>


bool file_exists(const std::string& filepath)
{
	// _access函数文件存在时会返回0
	return static_cast<bool>(!_access(filepath.c_str(), 0));
}

int file_exists_demo()
{
	std::string filepath = "./fileexisttest1.cpp";
	std::cout << "file exist: " << file_exists(filepath) << "\n";
	return 0;
}

