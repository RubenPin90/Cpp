#include "ScalarConverter.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& ref) { (void)ref; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	(void)rhs;
	return *this;
}

//Static public methods
void ScalarConverter::convert(std::string str) {
	char *pos;
	double value = std::strtod(str.c_str(), &pos);
	if (*pos) {
		if (*pos == 'f' && !*(pos + 1))
			std::cout << "float\n";
		else {
			std::cerr << "Wrong input!";
			return;
		}	
	}
	std::cout << value;
}

//private methods
void ScalarConverter::printData(const std::string& c, const std::string& i, const std::string& f, const std::string& d) const {
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}
