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
	float aa = 1.0f;
	double bb = 1.0;

	float res1 = imath::fastinvsqrt(aa);
	double res3 = imath::fastinvsqrt(bb);

	std::cout<<"res1:"<<res1<<"\nres3:"<<res3<<std::endl;
	return 0;
}

