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

double PmergeMe::sortList(bool check) {
	double res = sortContainer(_list, "list", check);
	return (res);
}

double PmergeMe::sortDeque(bool check) {
	double res = sortContainer(_deq, "deque", check);
	return (res);
}


