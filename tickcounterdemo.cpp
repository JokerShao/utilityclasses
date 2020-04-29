#include "tickcounter.h"

#include <iostream>
#include <math.h>

void tickcounterdemo()
{
	START_TIMER(t);

	for (int i = 0; i < 1000; i++)
		std::cout << sqrt(i) << "\n";

	END_TIMER(t);
}

