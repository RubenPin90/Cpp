#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#define FAIL 1
#define SUCCESS 0
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

struct Date {
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

class BitcoinExchange {
	public:
		BitcoinExchange(const std::string& input);
		BitcoinExchange(const std::string& input, const std::string& csv);
		BitcoinExchange(const BitcoinExchange& ref);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
	private:
		void checkInput(const std::string &input) const;
		void loadDatabase(const std::string &csv) const;
		bool checkHeader(const std::string& line, std::string& delim) const;

		std::map<Date, float> _data;
};

typedef BitcoinExchange BitEx;

#endif
