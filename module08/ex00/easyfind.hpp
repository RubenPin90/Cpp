#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T &container, const int search_value) throw (std::invalid_argument) {
		typename T::const_iterator it = std::find(container.begin(), container.end(), search_value);
		if (*it != search_value) {
			std::ostringstream ost; 
			ost << "No match found for " << search_value;
			throw std::invalid_argument(ost.str());
		}
		return it;
}

template <typename T>
typename T::iterator easyfind(T &container, const int search_value) throw (std::invalid_argument) {
		typename T::iterator it = std::find(container.begin(), container.end(), search_value);
		if (*it != search_value) {
			std::ostringstream ost; 
			ost << "No match found for " << search_value;
			throw std::invalid_argument(ost.str());
		}
		return it;
}

#endif
