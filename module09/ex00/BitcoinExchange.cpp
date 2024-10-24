#include "BitcoinExchange.hpp"

BitEx::BitcoinExchange(const std::string &input) {
	checkInput(input);
	loadDatabase("data.csv");
}
BitEx::BitcoinExchange(const std::string &input, const std::string &csv) {
	checkInput(input);
	loadDatabase(csv);
}

BitEx::BitcoinExchange(const BitEx& ref) { 
	*this = ref;
}

BitEx::~BitcoinExchange() {}

BitEx& BitEx::operator=(const BitEx& rhs) {
	if (this == &rhs)
		return *this;
	this->_data = rhs._data;
	return *this;
}

void BitEx::checkInput(const std::string &input) const {
	std::ifstream fd;
	fd.open(input);
	
	//open file and check if valid.
}

void BitEx::loadDatabase(const std::string &csv) const {
	(void)csv;
	//open file and check if valid.
}