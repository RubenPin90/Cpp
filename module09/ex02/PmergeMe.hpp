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
	double timeToSort;

	std::cout << "_________ " << type << "_________ \n" << std::endl;
	for (int i = 1; i < _ac; ++i) {
		cont.push_back(std::atoi(_av[i]));
	}
	Container tmp = cont;

	clock_t start = clock();
	std::size_t comp = fordJohnsonSort(cont, test_mode);
	clock_t end = clock();
	timeToSort = ((double) (end - start)) / CLOCKS_PER_SEC;

	std::cout << "\nBefore: ";
	rp_tools::printContainer(tmp);
	std::cout << "After: ";
	rp_tools::printContainer(cont);
	rp_tools::checkIfSorted(cont);
	rp_tools::prnt("\nComparisons: ", comp, true);
	rp_tools::printResult(_ac - 1, type, timeToSort);
	return (timeToSort);
}


#endif
