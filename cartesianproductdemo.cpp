#include "cartesianproduct.h"

#include <iostream>
#include <vector>

struct foo {
	int i;
	char c;
	float f;
};

int cartesianproduct_demo()
{
	std::vector<int> ints{ 1, 2, 3 };
	std::vector<char> chars{ 'a', 'b' };
	std::vector<float> floats{ 1.1f, 2.2f, 3.3f };

	std::vector<foo> product;

	cartesian_product(
		std::back_inserter(product),
		std::make_pair(ints.begin(), ints.end()),
		std::make_pair(chars.begin(), chars.end()),
		std::make_pair(floats.begin(), floats.end())
	);

	for (const auto& x : product)
		std::cout << x.i << "      " << x.c << "      " << x.f << std::endl;

	return 0;
}

