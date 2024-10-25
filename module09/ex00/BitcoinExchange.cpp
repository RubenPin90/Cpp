#include "BitcoinExchange.hpp"

BitEx::BitcoinExchange(const std::string &input) {
	std::cout << "Bitcoin Exchange Constructor called." << std::endl;
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
	std::string line, delim;

	fd.open(input.c_str());
	if (!fd.is_open()) {
		std::cerr << "Error: Couldn't open file." << std::endl;
		return;
	}
	std::getline(fd,line);
	if (!checkHeader(line, delim)) {
		std::cerr << "Error" << std::endl;
	}
	// while (getline (fd, line)) {

	// }

	
	//open file and check if valid.
}

void BitEx::loadDatabase(const std::string &csv) const {
	(void)csv;
	//open file and check if valid.
}

bool BitEx::checkHeader(const std::string& header, std::string& delim) const {
	std::istringstream ss(header);
	std::string head, tale;
	std::cout << ss.str() << std::endl;
	ss >> head;
	ss >> delim;
	ss >> tale;
	std::cout << "Header is: " << head << delim << tale << std::endl;
	if (head == "date" && tale == "value" && delim == "|") {
		return true;
	} else if (head == "date" && tale == "exchange_rate" && delim == ",") {
		return true;
	}
	return false;
}
