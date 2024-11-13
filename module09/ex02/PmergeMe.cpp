#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char* av[]) : _ac(ac), _av(av) {
	if (!rp_tools::validInput(_ac, _av))
		throw std::runtime_error("Input invalid.");
}
PmergeMe::~PmergeMe() {}

//private - Can't be called outside of class.
PmergeMe::PmergeMe() : _ac(0) {}
PmergeMe::PmergeMe(const PmergeMe& ref) : _ac(ref._ac) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& ) { return *this; }

double PmergeMe::sortList() {
	clock_t start = clock();
	for (int i = 0; i < _ac; ++i)
		_list.push_back(std::atoi(_av[i]));
	clock_t end = clock();
	std::cout << "Before: ";
	rp_tools::printContainer(_list);

	std::cout << "After: ";
	rp_tools::printContainer(_list);
	
	double time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	rp_tools::printResults(_ac, "std::list", time_used);
	return time_used;
}

double PmergeMe::sortDeque() {
	clock_t start = clock();
	for (int i = 0; i < _ac; ++i)
		_deq.push_back(std::atoi(_av[i]));
	clock_t end = clock();
	std::cout << "Before: ";
	rp_tools::printContainer(_deq);

	std::cout << "After: ";
	rp_tools::printContainer(_deq);
	
	double time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	rp_tools::printResults(_ac, "std::list", time_used);
	return time_used;

}


