#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <deque>
#include <list>
#include <cstdlib>
#include "rp_tools.hpp"
#include "fordJohnsonSort.hpp"
#define FAIL 1
#define SUCCESS 0

class PmergeMe {
	public:
		PmergeMe(int ac, char* av[]);
		PmergeMe(int ac, char* av[], bool describe);
		~PmergeMe();
		double sortList(bool describe);
		double sortDeque(bool describe);
	
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& ref);
		PmergeMe& operator=(const PmergeMe& rhs);
		template<typename Container>
    	double sortContainer(Container& cont, const std::string& type, bool check);

		std::deque<unsigned int> _deq;
		std::list<unsigned int> _list;
		const int _ac;
		char** _av;
};

template<typename Container>
double PmergeMe::sortContainer(Container& cont, const std::string& type, bool check) {
	double timeToSort, timeToConvert;

	std::cout << "_________ " << type << "_________ \n" << std::endl;
	clock_t start = clock();
	for (int i = 0; i < _ac; ++i)
		cont.push_back(std::atoi(_av[i]));
	clock_t end = clock();
	timeToConvert = ((double) (end - start)) / CLOCKS_PER_SEC;
	std::cout << "Before: ";
	rp_tools::printContainer(cont);

	start = clock();
	size_t comp = fordJohnsonSort(cont, check);
	(void)comp;
	end = clock();
	timeToSort = ((double) (end - start)) / CLOCKS_PER_SEC;

	std::cout << "After: ";
	rp_tools::printContainer(cont);
	rp_tools::printResults(_ac, type, timeToConvert, timeToSort);
	return (timeToConvert + timeToSort);
}


#endif
