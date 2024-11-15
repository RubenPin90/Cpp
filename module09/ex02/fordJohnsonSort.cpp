#include "fordJohnsonSort.hpp"

typedef std::deque<unsigned int>::iterator deqIt;
typedef std::list<unsigned int>::iterator listIt;



size_t fordJohnsonSort(std::deque<unsigned int>& deq, bool check) {
	size_t count = 0;
	size_t size = deq.size();
	std::deque<unsigned int> upper, lower;

	if (size < 2)
		return count;
	for (deqIt it = deq.begin(); it != deq.end(); it += 2) {
		if ((it + 1) != deq.end() && *it < *(it + 1)) {
			std::iter_swap(it, it + 1);
			upper.push_back(*it);
			lower.push_back(*(it + 1));
			count++;
		}
	}
	std::cout << "upper: ";
	for (deqIt it = upper.begin(); it != upper.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "lower: ";
	for (deqIt it = lower.begin(); it != lower.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << count << std::endl;
	fordJohnsonSort(upper, check);
	return count;
}

size_t fordJohnsonSort(std::list<unsigned int>& list, bool check) {
	size_t count = 0;
	(void)list;
	(void)check;
	return count;
}
