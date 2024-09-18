#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& ref) { (void)ref; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	(void)rhs;
	return *this;
}

//Static methods
void ScalarConverter::convert(std::string str) {
	std::cout << str << " firsttest\n";
}
