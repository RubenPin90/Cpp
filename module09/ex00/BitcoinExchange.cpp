#include "BitcoinExchange.hpp"
#define SUFFIX 4

BitEx::BitcoinExchange(const std::string &input) {
	std::cout << "Bitcoin Exchange Constructor called." << std::endl;
	loadDatabase("data.csv");
	loadInput(input);
}
BitEx::BitcoinExchange(const std::string &input, const std::string &csv) {
	std::cout << "Bitcoin Exchange Constructor with specific CSV called." << std::endl;
	loadDatabase(csv);
	loadInput(input);
}
BitEx::BitcoinExchange(const BitEx& ref) { *this = ref; }
BitEx::~BitcoinExchange() {}
BitEx& BitEx::operator=(const BitEx& rhs) {
	if (this == &rhs)
		return *this;
	this->_data = rhs._data;
	return *this;
}

const std::map<time_t, float>& BitEx::getdata() const {
	return _data;
}


void BitEx::open_wrapper(const std::string &input, std::ifstream& fd, std::string& delim, bool iscsv) {
	std::string line;
	std::ostringstream ost;

	fd.open(input.c_str());
	if (!fd.is_open()) {
		ost << "Failed to open file: " << input;
		throw std::runtime_error(ost.str());
	}
	std::getline(fd,line);
	if (!checkHeader(line, delim, iscsv)) {
		ost << "Invalid file header: " << "\' " << line << " \' " << "in " << input;
		throw std::logic_error(ost.str());
	}
}

static void	trim(std::string& str) {
	const char* whitespace = " ";
	std::size_t start = str.find_first_not_of(whitespace);
	std::size_t end = str.find_last_not_of(whitespace);
	if (start != end)
		str = str.substr(start, end - start + 1);
}

static bool checkDelim(const std::string& line, std::size_t& tmp, const std::string& delim) {
	tmp = line.find(delim);
	if (tmp != std::string::npos && (tmp != 10 || line[tmp + delim.length()] == ' '))
		tmp = std::string::npos;
	return tmp == std::string::npos;
}

static int daysInMonth(const Date& now) {
	switch(now.month) {
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			return (now.year % 4 == 0 && (now.year % 100 != 0 || now.year % 400 == 0)) ? 29 : 28;
		default:
			return 31;
	}
}

static bool checkDate(time_t& time, const std::string& line, const std::size_t pos) {
	std::string dateStr = line.substr(0, pos);
	trim(dateStr);
	if (dateStr.length() != 10)
		return false;
	std::istringstream date(dateStr);
	Date now;
	char sep1, sep2;
	date >> now.year >> sep1 >> now.month >> sep2 >> now.day;
	if (date.fail() || sep1 != '-' || sep2 != '-' || now.year < 0 || now.month < 1 || \
					now.month > 12 || now.day < 1 || now.day > daysInMonth(now)) {
		return false;
	}
	static std::tm tmp;
	tmp.tm_year = now.year - 1900;
	tmp.tm_mon = now.month - 1;
	tmp.tm_mday = now.day;
	time = std::mktime(&tmp);
	return true;
}

static bool checkValue(const std::string& line, const std::size_t& pos, \
						const std::string& delim, float& value, bool range) {
	std::string rateStr = line.substr(pos + delim.length());
	std::istringstream rate(rateStr);
	rate >> value;
	if (!rate.eof() || rate.fail() ||  value < 0.0f || (range && (value > 1000.0f)))
		return false;
	return true;
}

bool BitEx::checkHeader(std::string& header, std::string& delim, bool iscsv) const {
	if(header == "date | value" && iscsv == false) {
		delim = " | ";
		return true;
	}
	else if (header == "date,exchange_rate" && iscsv == true) {
		delim = ",";
		return true;
	}
	return false;
}

void BitEx::loadInput(const std::string& input) {
	time_t date;
	float value;
	std::ifstream fd;
	std::string line, delim;
	std::size_t pos;

	open_wrapper(input, fd, delim, false);
	for (int i = 2; std::getline(fd, line); ++i) {
		if (line.empty())
			continue;
		if (checkDelim(line, pos, delim)) {
			std::cerr << "Error: Invalid input at line: " << i << std::endl;
			continue;
		}
		if (!checkDate(date, line, pos)) {
			std::cerr << "Error: Invalid date at line: " << i << std::endl;
			continue;
		}
		if (!checkValue(line, pos, delim, value, true)) {
			std::cerr << "Error: Invalid value at line: " << i << std::endl;
			continue;
		}
		std::map<time_t, float>::const_iterator it = _data.lower_bound(date);
		if (it->first == date) {
			std::cout << std::fixed << std::setprecision(2) << "[ " << i << " ] " << convertDate(date) << " => " << value << " = " << value*it->second << std::endl;
		} else if (it == _data.begin()) {
			std::cerr << "No exchange rate found for date: " << convertDate(date) << " at line " << i << std::endl;
			continue;
		} else {
			--it;
			std::cout << std::fixed << std::setprecision(2) << "[ " << i << " ] " << convertDate(date) << " => " << value << " = " << value*it->second << std::endl;
		}
	}
}

void BitEx::loadDatabase(const std::string &csv) {
	time_t date; 
	float value;
	std::ifstream fd;
	std::ostringstream ost;
	std::string line, delim;
	std::size_t pos, len;
	
	len = csv.length();
	if (len < SUFFIX || csv.compare(len - SUFFIX, SUFFIX, ".csv") != 0)
		throw std::logic_error("Invalid data filename: Needs to be .csv");
	open_wrapper(csv, fd, delim, true);

	for (int i = 2; std::getline(fd, line); ++i) {
		if (line.empty()) {
			ost << "[" << csv << "-Error] " << "Empty line at line: " << i;
			throw std::logic_error(ost.str());
		}
		if (checkDelim(line, pos, delim)) {
			ost << "[" << csv << "-Error] " << "Invalid delimitor at line: " << i;
			throw std::logic_error(ost.str());
		}
		if (!checkDate(date, line, pos)) {
			ost << "[" << csv << "-Error] " << "Invalid date at line: " << i;
			throw std::logic_error(ost.str());
		}
		if (!checkValue(line, pos, delim, value, false)) {
			ost << "[" << csv << "-Error] " << "Invalid Exchange Rate at line: " << i;
			throw std::logic_error(ost.str());
		}
		_data[date]= value;
	}
}

std::string BitEx::convertDate(const time_t& date) {
	std::stringstream sst;
	std::tm* tm_date = std::localtime(&date);
	sst << tm_date->tm_year + 1900 << "-";
	sst << std::setfill('0') << std::setw(2) << tm_date->tm_mon + 1 << "-";
	sst << std::setfill('0') << std::setw(2) << tm_date->tm_mday;
	return sst.str();	
}

std::ostream& operator<<(std::ostream& ost, const BitEx& rhs) {
	int i = 1;
	for (std::map<time_t, float>::const_iterator it = rhs.getdata().begin(); it != rhs.getdata().end(); ++it) {
		std::tm* tm_date = std::localtime(&it->first);
		ost << ++i << " " << tm_date->tm_year + 1900 << "-";
		ost << std::setfill('0') << std::setw(2) << tm_date->tm_mon + 1 << "-";
		ost << std::setfill('0') << std::setw(2) << tm_date->tm_mday;
		if (static_cast<int>(it->second) == it->second)
			ost << " " << static_cast<int>(it->second) << std::endl;
		else
			ost << " " << std::fixed << std::setprecision(2) << it->second << std::endl;
	}
	return ost;
}

// Another checkHeader implementation through stringstream:
// bool BitEx::checkHeader(const std::string& header, std::string& delim) const {
	// std::istringstream ss(header);
	// std::string head, tail;
	// size_t tmp;
	// ss >> head >> delim >> tail;
	// if ((tmp = head.find_first_of("|,")) != std::string::npos) {
	// 	if (!delim.empty())
	// 		tail = delim;
	// 	else
	// 		tail = head.substr(tmp + 1);
	// 	delim = head[tmp];
	// 	head = head.substr(0, tmp);
	// } else if (delim.size() > 1 && (tmp = delim.find_first_of("|,")) != std::string::npos) {
	// 	tail = delim;
	// 	delim = tail[tmp];
	// 	tail = tail.substr(tmp + 1);
	// }
	// std::cout << "Header is: " << head << " " << delim << " " << tail << std::endl;
	// if (head == "date" && tail == "value" && delim == "|") {
	// 	return true;
	// } else if (head == "date" && tail == "exchange_rate" && delim == ",") {
	// 	return true;
	// }
	// return false; }

// 	bool BitEx::checkHeader(const std::string& header, std::string& delim) const {
// 	std::string head, tail;
// 	std::size_t pos;
// 	pos = header.find_first_of("|,");
// 	if (pos != std::string::npos) {
// 		delim = header[pos];
// 		head = header.substr(0, pos);
// 		tail = header.substr(pos + 1);
// 		trim(head);
// 		trim(tail);
// 		if (head != "date" || !(tail == "value" || tail == "exchange_rate") || 
// 												!(delim == "|" || delim == ","))
// 			return false;
// 	} else {
// 		return false;
// 	}
// 	return true;
// }
