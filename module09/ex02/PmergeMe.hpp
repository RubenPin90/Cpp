#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <deque>
#include <list>
#include <cstdlib>
#include "rp_tools.hpp"
#define FAIL 1
#define SUCCESS 0

class PmergeMe {
	public:
		PmergeMe(int ac, char* av[]);
		~PmergeMe();
		double sortList();
		double sortDeque();
	
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& ref);
		PmergeMe& operator=(const PmergeMe& rhs);

		std::deque<unsigned int> _deq;
		std::list<unsigned int> _list;
		const int _ac;
		char** _av;
};

#endif
