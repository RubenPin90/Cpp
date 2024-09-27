#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <iostream>

enum e_info {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	FAIL
};

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& ref);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& rhs);

	public:
		static void convert(const std::string& str);
};

#endif
