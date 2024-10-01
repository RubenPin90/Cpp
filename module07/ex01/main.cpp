#include "iter.hpp"
#include <iostream>

inline void printThing(int i) { std::cout << i << std::endl; }
inline void printThing(std::string str) { std::cout << str << std::endl; }

int main (void) {
	std::string stringArray[]	= {"test1", "test2", "test3"};
	int length = sizeof(stringArray) / sizeof(std::string);
	::iter(stringArray, length, printThing);

	int intArray[] = {1,2,3,4,5,6,7,8,9,10};
	length = sizeof(intArray) / sizeof(int);
	::iter(intArray, length, printThing);
	return 0;
}
