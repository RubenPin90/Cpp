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
double PmergeMe::sortContainer(Container& cont, const std::string& type, bool test_mode) {
	double timeToSort, timeToConvert;

	std::cout << "_________ " << type << "_________ \n" << std::endl;
	clock_t start = clock();
	for (int i = 1; i < _ac; ++i) {
		cont.push_back(std::atoi(_av[i]));
	}
	clock_t end = clock();
	timeToConvert = ((double) (end - start)) / CLOCKS_PER_SEC;
	Container tmp = cont;

	start = clock();
	size_t comp = fordJohnsonSort(cont, test_mode);
	end = clock();
	timeToSort = ((double) (end - start)) / CLOCKS_PER_SEC;

	std::cout << "\nBefore: ";
	rp_tools::printContainer(tmp);
	std::cout << "After: ";
	rp_tools::printContainer(cont);
	rp_tools::prnt("\nComparisons: ", comp, test_mode);
	rp_tools::printResults(_ac - 1, type, timeToConvert, timeToSort);
	return (timeToConvert + timeToSort);
}


#endif
