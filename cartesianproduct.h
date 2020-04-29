#pragma once
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

