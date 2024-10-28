#include "BitcoinExchange.hpp"
#define SUFFIX 4

BitEx::BitcoinExchange(const std::string &input) {
	std::cout << "Bitcoin Exchange Constructor called." << std::endl;
	loadDatabase("data.csv");
	loadInput(input);
}
BitEx::BitcoinExchange(const std::string &input, const std::string &csv) {
	loadDatabase(csv);
	(void)input;
	// loadFile(input);
}
BitEx::BitcoinExchange(const BitEx& ref) { *this = ref; }
BitEx::~BitcoinExchange() {}
BitEx& BitEx::operator=(const BitEx& rhs) {
	if (this == &rhs)
		return *this;
	this->_data = rhs._data;
	return *this;
}

const std::map<Date, float>& BitEx::getdata() const {
	return _data;
}


void BitEx::loadInput(const std::string& input) {
	std::ifstream fd;
	std::string line, delim;

	open_wrapper(input, fd, delim);
	while (std::getline(fd, line)) {

	}
}

static size_t checkDelim(const std::string& line, const std::string& delim, const int& i) {
	std::size_t tmp = line.find(delim);
	if (tmp == std::string::npos) {
		std::ostringstream ost;
		ost << "Invalid delimitor at line " << i;
		throw std::logic_error(ost.str());
	}
	return tmp;
}

void BitEx::loadDatabase(const std::string &csv) {
	std::ifstream fd;
	std::ostringstream ost;
	std::string line, delim;
	size_t len = csv.length();
	if (len < SUFFIX || csv.compare(len - SUFFIX, SUFFIX, ".csv") != 0)
		throw std::logic_error("Invalid data filename: Needs to be .csv");
	open_wrapper(csv, fd, delim);

	for (int i = 2; std::getline(fd, line); ++i) {
		size_t tmp = checkDelim(line, delim, i);
		checkDate(line.substr(0, tmp))
		std::string dateStr = line.substr(0, tmp);
		if (dateStr.length() != 10) {
			ost << "Invalid date syntax at line " << i;
			throw std::logic_error(ost.str());
		}
		std::istringstream date(dateStr);
		Date now; 
		char sep1, sep2;
	
		date >> now.year >> sep1 >> now.month >> sep2 >> now.day;
		if (date.fail() || sep1 != '-' || sep2 != '-' || now.year < 0 || now.month < 1 || \
						now.month > 12 || now.day < 1 || now.day > 31) {
			ost << "Date is not correct at line: " << i;
			throw std::logic_error(ost.str());
		}

		std::string rateStr = line.substr(tmp + 1);
		std::istringstream rate(rateStr);
		float f_value;
		rate >> f_value;
		if (!rate.eof() || rate.fail() ||  f_value < 0.0f) {
			ost << "Invalid Exchange Rate at line: " << i;
			throw std::logic_error(ost.str());
		}
		_data.insert(std::make_pair(now, f_value));
	}
}

void BitEx::open_wrapper(const std::string &input, std::ifstream& fd, std::string& delim) {
	std::string line;
	std::ostringstream ost;

	fd.open(input.c_str());
	if (!fd.is_open()) {
		ost << "Failed to open file: " << input;
		throw std::runtime_error(ost.str());
	}
	std::getline(fd,line);
	if (!checkHeader(line, delim)) {
		ost << "Invalid file header: " << line;
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

bool BitEx::checkHeader(const std::string& header, std::string& delim) const {
	std::string head, tail;
	std::size_t pos;
	pos = header.find_first_of("|,");
	if (pos != std::string::npos) {
		delim = header[pos];
		head = header.substr(0, pos);
		tail = header.substr(pos + 1);
		trim(head);
		trim(tail);
		if (head != "date" || !(tail == "value" || tail == "exchange_rate") || \
												!(delim == "|" || delim == ","))
			return false;
	} else {
		return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream& ost, const BitEx& rhs) {
	int i = 0;
	for (std::map<Date, float>::const_iterator it = rhs.getdata().begin(); it != rhs.getdata().end(); ++it) {
		ost << ++i << " " << it->first.year << "-" << it->first.month << "-" << it->first.day;
		ost << " " << it->second << std::endl;
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
