#ifndef INTERPOLATION_SEARCH_HPP__
#define INTERPOLATION_SEARCH_HPP__

#include <vector>

template<typename T>
inline int position(const std::vector<T>& vec, const T& x, const int low, const int high) {
	return low + (high - low) * ((x - vec.at(low)) / (vec.at(high) - vec.at(low)));
}

template<typename T>
int interpolation_search(const std::vector<T>& vec, const T& x) {
	int low = 0;
	int high = vec.size() - 1;

	while (low <= high && x >= vec.at(low) && x <= vec.at(high)) {
		int pos = position(vec, x, low, high);
		if (vec.at(pos) == x) {
			return pos;
		}

		if (vec.at(pos) < x) {
			low = pos + 1;
			continue;
		}

		high = pos - 1;
	}

	return -1;
}

#endif //
