#ifndef RP_TOOLS_HPP
#define RP_TOOLS_HPP
#include <cctype>
#include <iostream>
#include <sstream>
#include <limits>
#include <list>
#include <deque>
#define RED "\033[31m"
#define GREY "\033[2m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

namespace rp_tools {
	bool validInput(const int ac, char* av[]);
	void printResult(const int count, const std::string& type, const double sortTime);
	std::size_t gen_jacobsthal(std::size_t num);

	template<typename T>
	void checkIfSorted(const T& cont) {
		typename T::const_iterator tmp = cont.begin();
		bool sorted = true;

		for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it) {
			if(it != cont.begin() && *tmp > *it)
				sorted = false;
			tmp = it;
		}
		std::cout << "Sequence is sorted: ";
		if (sorted)
			std::cout << GREEN << "\u2714" << RESET << std::endl;
		else
			std::cout << RED << "\u2718" << RESET << std::endl;
	}

	template<typename T>
	void printContainer(const T& cont) {
		for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	template<typename T>
	void printContainer(const T& cont, std::size_t c_size) {
		std::size_t pos = 0;
		for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it) {
			std::size_t dist = std::distance(it, cont.end());
			if (pos % c_size == 0 && dist >= c_size) {
				std::cout << *it << " ";
			} else if (pos % c_size  == 0 && dist < c_size) {
				std::cout << RED << *it << RESET << " ";
			} else {
				std::cout << GREY << *it << RESET << " ";
			}
			++pos;
		}
		std::cout << std::endl;
	}

	template <typename T>
	void prnt(const std::string& str, const T& value, bool check) {
		if (check)
			std::cout << str << value << std::endl; 
	}
}

#endif
