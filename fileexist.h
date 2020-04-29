#pragma once

#include <corecrt_io.h>


inline bool file_exists(const char* filepath) {
	// _access函数文件存在时会返回0
	return static_cast<bool>(!_access(filepath, 0));
}

