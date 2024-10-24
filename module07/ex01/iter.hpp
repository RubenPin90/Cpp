#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>
#include <string>

//also possible to send void (*func)(T&) but 
//then there need to be (const T&) to cover const types.
template<typename T, typename F>
void iter(T *array, size_t len, F funcptr) {
	for (size_t i = 0; i < len; i++)
		funcptr(array[i]);
}

#endif
