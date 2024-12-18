#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#define WRONG_DATE 2
#define FAIL 1
#define SUCCESS 0
#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <utility>
#include <ctime>

struct Date {
	int day;
	int month;
	int year;
};

class BitcoinExchange {
	public:
		BitcoinExchange(const std::string& input);
		BitcoinExchange(const std::string& input, const std::string& csv);
		BitcoinExchange(const BitcoinExchange& ref);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		const std::map<time_t, float>& getdata() const;

	private:
		void loadDatabase(const std::string &csv);
		void loadInput(const std::string &input);
		void open_wrapper(const std::string &file, std::ifstream& fd, std::string& delim, bool iscsv);
		bool checkHeader(std::string& line, std::string& delim, bool iscsv) const;
		std::string convertDate(const time_t& date);

		std::map<time_t, float> _data;
};

typedef BitcoinExchange BitEx;
std::ostream& operator<<(std::ostream& ost, const BitEx& rhs);


#endif
