#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <deque>
#include <list>
#define FAIL 1
#define SUCCESS 0

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& ref);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& rhs);
	
	private:
		std::deque<unsigned int> deq;
		std::list<unsigned int> list;
};

#endif
