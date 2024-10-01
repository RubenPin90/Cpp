#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <string>
#include <iostream>

template<typename T>
void swap(T &a, T &b) {
	return (std::swap(a, b));
} 

template<typename T>
T const& min(T &a, T&b) {
	return ((a < b) ? a : b);
}

template<typename T>
T const& max(T &a, T&b) {
	return ((a > b) ? a : b);
}

#endif
