#pragma once


/* Timer macros. Usage:
 * '''
 * START_TIMER(myFunkyTimer);
 * doHeavyCode();
 * END_TIMER(myFunkyTimer);
 * '''
 */
#include <chrono>
#include <iostream>

#define START_TIMER(t) auto t = std::chrono::steady_clock::now();

#define END_TIMER(t) { \
	std::cout << "timer " << #t << ": " << \
	std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - t).count() / 1000.f << \
	"ms";}

