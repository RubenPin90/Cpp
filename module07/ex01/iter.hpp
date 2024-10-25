#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>
#include <string>
#include <iostream>

//Using typename F is more flexible but requires careful handling to avoid ambiguity with overloads, 
//while (void)(*func)(T&) provides more control at the cost of flexibility with const and callable types:
// template<typename T, typename F>
// void iter(T *array, size_t len, F funcptr) {
// 	for (size_t i = 0; i < len; i++)
// 		funcptr(array[i]);
// }

template<typename T>
void iter(T *array, size_t len, void (*func)(T&)) {
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

template<typename T>
void iter(T *array, size_t len, void (*func)(const T&)) {
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

#endif
