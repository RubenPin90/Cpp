#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& ) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ) { return *this; }


static e_info defineType(const std::string& str, TypeInfo& stat) {
	char *pos;
	stat.value = std::strtod(str.c_str(), &pos);
	if (str.length() == 1 && !isdigit(str[0])) 
		return CHAR;
	if (*pos) {
		if ((*pos == 'f' && !*(pos + 1)) || str == "-inff" || str == "+inff" || str == "nanf")
			return FLOAT;
		else
			return FAIL;
	}
	if (str.find('.') == std::string::npos && stat.value >= std::numeric_limits<int>::min() && stat.value <= std::numeric_limits<int>::max())
		return INT;
	return DOUBLE;
}

static std::string strCatalogue(e_info type) {
	std::string catalogue[] = {"char", "int", "float", "double", "invalid"};
	return catalogue[type];
}

static void defineStatus(const std::string& str, TypeInfo& stat) {
	
	switch (stat.type) {
		case CHAR: {
			if (str[0] < 32 || str[0] > 126)
				stat.CharStatus = NONDISPLAYABLE;
			else if (str[0] < std::numeric_limits<char>::min() || str[0] > std::numeric_limits<char>::max())
				stat.CharStatus = IMPOSSIBLE;
			else
				stat.CharStatus = DISPLAYABLE;
			break;
		}
		case INT: {
			if (stat.value < std::numeric_limits<int>::min() || stat.value > std::numeric_limits<int>::max() || isnan(stat.value))
				stat.IntStatus = IMPOSSIBLE;
			else
				stat.IntStatus = DISPLAYABLE;
			break;
		}
		case FLOAT: {
			if (std::isnan(stat.value) || std::isinf(stat.value))
				stat.FloatStatus = DISPLAYABLE;
			else
				stat.FloatStatus = IMPOSSIBLE;
			break;
		}
		case DOUBLE: {
			stat.DoubleStatus = DISPLAYABLE;
			break;
		}
		case FAIL: {
			stat.CharStatus = IMPOSSIBLE;
			stat.IntStatus = IMPOSSIBLE;
			stat.FloatStatus = IMPOSSIBLE;
			stat.DoubleStatus = IMPOSSIBLE;
			break;
		}
		default: {
			break;
		}
	}


	
}

void ScalarConverter::convert(const std::string& str) {
	std::cout << "Input:\t'" << str << "'" << std::endl;
	TypeInfo valuestat;
	valuestat.type = defineType(str, valuestat);
	std::cout << "Type:\t" << strCatalogue(valuestat.type) << "\n" << std::endl;
	if (valuestat.type == FAIL)
		return static_cast<void>(std::cout << "Input '" << str << "' is invalid! Bye");
	defineStatus(str, valuestat);
	std::cout << "char: " << valuestat.CharStatus << std::endl;
	std::cout << "int: " << valuestat.IntStatus << std::endl;
	std::cout << "float: " << valuestat.FloatStatus << std::endl;
	std::cout << "double: " << valuestat.DoubleStatus << std::endl;

	/*char *pos;
	double value = std::strtod(str.c_str(), &pos);
	if (*pos) {
		if (*pos == 'f' && !*(pos + 1)) {
		}
		else {
			std::cerr << "Wrong input!";
			return;
		}	
	}*/
	printData(str, valuestat);
}

//private methods
void ScalarConverter::printData(const std::string& str, const TypeInfo& type) {
	(void)str;
	(void)type;
	/*if (value < 32 || value > 126)
		std::cout << "char:\tNon displayable\n";
	else if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || isnan(value))
		std::cout << "char:\timpossible\n";
	else
		std::cout << "char:\t'" << static_cast<char>(value) << "'\n";
	
	std::cout << "int:\t" << static_cast<int>(value) << std::endl;
	std::cout << "float:\t" << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double:\t" << value << std::endl;*/
}
