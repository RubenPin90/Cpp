#ifndef DATA_HPP
#define DATA_HPP
#include <string>
#include <ostream>

struct Data {
	Data(int id = 0, const std::string& str1 = "", const std::string& str2 = "", const std::string& str3 = "");
	int			id;
	std::string first;
	std::string second;
	std::string third;
};

std::ostream& operator<<(std::ostream& ost, const Data& rhs);

#endif
