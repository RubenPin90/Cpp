#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& ) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ) { return *this; }


static e_info defineType(const std::string& str, const double& value, const char* pos) {
	if (str.length() == 1 && !isdigit(str[0])) 
		return CHAR;
	if (*pos) {
		if ((*pos == 'f' && !*(pos + 1)) || str == "-inff" || str == "+inff" || str == "nanf")
			return FLOAT;
		else
			return FAIL;
	}
	if (str.find('.') == std::string::npos && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
		return INT;
	return DOUBLE;
}

inline static std::string strCatalogue(int type) {
	std::string catalogue[] = {"char", "int", "float", "double", "invalid"};
	return catalogue[type];
}

static std::string& defineStatus(const double& value, e_info type, std::string status[4]) {
	if (value < std::numeric_limits<unsigned char>::min() || value > std::numeric_limits<unsigned char>::max() || isnan(value))
		status[CHAR] = "impossible";
	else if (type != CHAR && (value < 32 || value > 127))
		status[CHAR] = "Non displayable";
	else
		status[CHAR] = "valid";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || isnan(value))
		status[INT] = "impossible";
	else
		status[INT] = "valid";
	if (std::isnan(value) || std::isinf(value) || (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max()))
		status[FLOAT] = "valid";
	else
		status[FLOAT] = "impossible";
	status[DOUBLE] = "valid";
	return *status;
}

static void printer(double value, const std::string status[4]) {
	for (e_info i = CHAR; i <= DOUBLE; i = static_cast<e_info>(i + 1)) {
		std::cout << strCatalogue(i) << ": ";
		if (status[i] == "valid") {
			switch (i) {
				case CHAR: {
					std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
					break;
				} 
				case INT: {
					std::cout << static_cast<int>(value) << std::endl;
					break;
				}
				case FLOAT: {
					std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
					break;
				}
				case DOUBLE: {
					std::cout << static_cast<double>(value) << std::endl;
					break;
				}
				default: {
					break;
				}
			}
		}
		else
			std::cout << status[i] << std::endl;
	}
}

static void printData(const std::string& str, const std::string status[4], e_info type) {
	switch (type) {
		case CHAR: {
			unsigned char value = str[0];
			printer(value, status);
			break;
		}
		case INT: {
			int value = std::atoi(str.c_str());
			printer(value, status);
			break;
		}
		case FLOAT: {
			float value = std::strtof(str.c_str(), NULL);
			printer(value, status);
			break;
		}
		case DOUBLE: {
			double value = std::strtod(str.c_str(), NULL);
			printer(value, status);
			break;
		}
		default: {
			break;
		}
	}
}

void ScalarConverter::convert(const std::string& str) {
	char *pos;
	double value = std::strtod(str.c_str(), &pos);
	e_info type = defineType(str, value, pos);
	std::cout << "Input:\t'" << str << "'" << std::endl;
	std::cout << "Type:\t" << strCatalogue(type) << "\n" << std::endl;
	if (type == FAIL)
		return static_cast<void>(std::cout << "Input '" << str << "' is invalid! Bye");
	std::string status[4];
	defineStatus(value, type, status);
	printData(str, status, type);
}
