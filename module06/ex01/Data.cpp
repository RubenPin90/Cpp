#include "Data.hpp"

Data::Data(int ac, const std::string& str1, const std::string& str2, const std::string& str3) : id(ac), first(str1), second(str2), third(str3) {}

std::ostream& operator<<(std::ostream& ost, const Data& rhs) {
	ost << "++++++++++Data Info+++++++++++++\n";
	ost << "Input count:\t" << rhs.id << "\n";
	ost << "1. Input:\t" << rhs.first << "\n";
	ost << "2. Input:\t" << rhs.second << "\n";
	ost << "3. Input:\t" << rhs.third << std::endl;
	return ost;
}