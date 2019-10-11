#include <iostream>
#include <vector>
#include <tuple>


template <typename T, typename B>
bool increment(const B& begins, std::pair<T, T>& r) {
	++r.first;
	return (r.first == r.second);
}
template <typename T, typename... TT, typename B>
bool increment(const B& begins, std::pair<T, T>& r, std::pair<TT, TT>&... rr) {
	++r.first;
	if (r.first == r.second) {
		r.first = std::get<std::tuple_size<B>::value - sizeof...(rr) - 1>(begins);
		return increment(begins, rr...);
	}
	return false;
}
template <typename OutputIterator, typename... Iter>
void cartesian_product(OutputIterator out, std::pair<Iter, Iter>... ranges) {
	const auto begins = std::make_tuple(ranges.first...);
	for (;;) {
		out = { *ranges.first... };
		if (increment(begins, ranges...)) break;
	}
}


struct foo {
	int i;
	char c;
	float f;
};

int cartesianproduct_demo()
{
	std::vector<int> ints{ 1, 2, 3 };
	std::vector<char> chars{ 'a', 'b'};
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

