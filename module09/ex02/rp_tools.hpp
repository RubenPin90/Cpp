#ifndef RP_TOOLS_HPP
#define RP_TOOLS_HPP
#include <cctype>
#include <iostream>
#include <sstream>
#include <limits>

namespace rp_tools {
	bool validInput(const int ac, char* av[]);
	void printResults(const int count, const std::string& type, const double convTime, const double sortTime);

	template<typename T>
	void printContainer(const T& cont) {
		for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

#endif
