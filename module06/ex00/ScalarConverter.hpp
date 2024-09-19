#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <iostream>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& ref);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& rhs);

		void printData(const std::string& c, const std::string& i, const std::string& f, const std::string& d) const;

	public:
		static void convert(std::string str);
		
};

#endif
