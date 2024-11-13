#include "rp_tools.hpp"

static bool checkNumber(const std::string& num) {
	if(num.empty())
		return false;
	for (int j = 0; num[j]; ++j)
		if (!std::isdigit(num[j]))
			return false;
	std::istringstream ist(num);
	long tmp;
	ist >> tmp;
	if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min())
		return false;
	return true;
}

bool rp_tools::validInput(const int ac, char* av[]) {
	(void)ac;
	for (int i = 1; av[i]; ++i) {
		if (!checkNumber(av[i])) {
			std::cerr << "Invalid number detected at " << av[i] << std::endl;
			return false;
		}
	}
	return true;
}

void rp_tools::printResults(const int count, const std::string& type, const double time) {
	std::cout << "\nTime to process a range of " << count << " elements with std::" << type;
	std::cout << ": " << std::fixed << time << " seconds.\n" << std::endl;
}
