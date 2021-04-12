#include <cmath>

std::pair<int, int> operator -(const std::pair<int, int>& x, const std::pair<int, int>& y) {
	return std::make_pair(x.first - y.first, x.second - y.second);
}

std::pair<int, int> operator +(const std::pair<int, int>& x, const std::pair<int, int>& y) {
	return std::make_pair(x.first + y.first, x.second + y.second);
}
