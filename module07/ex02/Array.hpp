#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
template<typename T = int>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& ref);
		~Array();
		Array& operator=(const Array& rhs);
		T& operator[](unsigned int i);
		const T& operator[](unsigned int i) const;
		unsigned int size() const;
	private:
		T* _data;
		unsigned int _size;
};

#include "Array.tpp"

#endif

