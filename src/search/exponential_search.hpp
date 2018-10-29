// 指数搜索

#ifndef EXPONENTIAL_SEARCH_HPP__
#define EXPONENTIAL_SEARCH_HPP__

#include <vector>
#include <algorithm>

template<typename T>
int exponential_search(const std::vector<T>& vec, const T& x) {
	// x is present at first location itself
	if (vec.at(0) == x) {
		return 0;
	}

	// Find range for binary search by repeated doubling
	const int length = vec.size();
	int i = 1;
	while (i < length && vec.at(i) <= x) {
		i *= 2;
	}

	// range is  [i / 2 , vec.size())
	int low = i / 2;
	int high = std::min(i, length - 1);
	return binary_search(vec, low, high, x);
}

#endif
