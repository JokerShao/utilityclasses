#include <iostream>
#include <cmath>
#include "../../mathematics/imath.h"

/* Timer macros. Usage:
 * '''
 * START_TIMER(myFunkyTimer);
 * doHeavyCode();
 * END_TIMER(myFunkyTimer);
 * '''
 */

#include <string>
#include <sstream>

/**
* A series of function to help with basic input and output.
* */

// /** Prints the given error message */
// void Error(const std::string& msg);

// /** Prints the given warning message. */
// void Warning(const std::string& msg);

// /** Prints the given information message. */
// void Inform(const std::string& msg);

void Error(const std::string& msg)
{
    std::cerr << "ERROR: " << msg << "\n";
}

void Warning(const std::string& msg)
{
    std::cout << "Warning: " << msg << "\n";
}

void Inform(const std::string& msg)
{
    std::cout << ":- " << msg << "\n";
}

/** Converts the input to a string. */
template <class T>
std::string ToString(const T t)
{
    std::ostringstream ss;
    ss << t;
    return ss.str();
}

#include <chrono>

#define START_TIMER(t) auto t = std::chrono::system_clock::now();

#define END_TIMER(t) {Inform("Stopping timer: "#t + std::string(" : ") + \
    ToString(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - t).count()));}

int main(int argc, const char * argv[])
{
	float a = 1.f;

	int n = 0;
	float res;
	START_TIMER(t1);
	for (n = 0; n < 99999900; n++)
	{
		res = imath::fastinvsqrt(a, 1);
		// res = 0;
	}
	END_TIMER(t1);

	std::cout << "fast invsqrt res:" << res << "\n";

	float resb;
	START_TIMER(t2);
	for (n = 0; n < 99999900; n++)
	{
		resb = 1 / sqrt(a);
		// resb = 0;
	}
	END_TIMER(t2);
	std::cout << "std invsqrt res:" << resb << "\n";

	return 0;
}

