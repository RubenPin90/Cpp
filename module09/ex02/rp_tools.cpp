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

void rp_tools::printResults(const int count, const std::string& type, const double convTime, const double sortTime) {
	
	std::cout << "\nTime to convert argv data to std::" << type << ": "; 
	std::cout << std::fixed << sortTime << " seconds." << std::endl;
	std::cout << "Time to process a range of " << count << " elements with std::" << type;
	std::cout << ": " << std::fixed << convTime << " seconds.\n" << std::endl;
}


// J(n) = J(n-1) + 2 * J(n-2)
size_t rp_tools::gen_jacobsthal(size_t num) {
	if(num == 0)
		return 0;
	if(num == 1)
		return 1;
	return gen_jacobsthal(num - 1) + 2 * gen_jacobsthal(num - 2);
}