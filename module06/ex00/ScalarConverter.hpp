#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <iostream>

enum e_info {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	FAIL,
	DISPLAYABLE,
	NONDISPLAYABLE,
	IMPOSSIBLE
};

struct TypeInfo {
	e_info type;
	double value;
	e_info CharStatus;
	e_info IntStatus;
	e_info FloatStatus;
	e_info DoubleStatus;
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
