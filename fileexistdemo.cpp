#include "fileexist.h"
#include <iostream>


int file_exists_demo()
{
	std::string filepath = "./fileexisttest1.cpp";
	std::cout << "file exist: " << file_exists(filepath.c_str()) << "\n";
	return 0;
}

