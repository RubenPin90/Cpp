#include "fordJohnsonSort.hpp"

typedef std::deque<unsigned int>::iterator deqIt;
typedef std::list<unsigned int>::iterator listIt;

void test_print(std::deque<unsigned int>& upper, std::deque<unsigned int>& lower, int struggler) {
	std::cout << "upper: ";
	for (deqIt it = upper.begin(); it != upper.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "lower: ";
	for (deqIt it = lower.begin(); it != lower.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "struggler: " << struggler << std::endl;
}


void fJ_impl(std::deque<unsigned int>& deq, const size_t size, size_t& count, bool test_mode, size_t lvl) {
	std::deque<unsigned int> upper, lower;
	int struggler = -1;

	if (size < 2)
		return;
	if (size % 2 == 0) {
		for (deqIt it = deq.begin(); it != deq.end(); it += 2) {
			if ((it + 1) != deq.end() && *it < *(it + 1)) {
				std::iter_swap(it, it + 1);
			}
			upper.push_back(*it);
			lower.push_back(*(it + 1));
			count++;
		}
	} else {
		for (deqIt it = deq.begin(); it != deq.end() - 1; it += 2) {
			if ((it + 1) != deq.end() && *it < *(it + 1)) {
				std::iter_swap(it, it + 1);
			}
			upper.push_back(*it);
			lower.push_back(*(it + 1));
			count++;
		}	
		struggler = *(deq.end() - 1);
	}
	if (test_mode == true)
		test_print(upper, lower, struggler);
	fJ_impl(upper, upper.size(), count, test_mode, ++lvl);

	std::deque<unsigned int> result;
	result.insert(result.end(), lower.front());
	result.insert(result.end(), upper.front());

	if (size % 2 != 0) {
		deqIt it = std::lower_bound(result.begin(), result.end(), struggler);
		result.insert(it, struggler);
	}

	deq = result;
	std::cout << "\ndeq: ";
	for(deqIt it = deq.begin(); it != deq.end(); ++it) {
		std::cout << *it << " ";
	}
}

size_t fordJohnsonSort(std::deque<unsigned int>& deq, bool test_mode) {
	size_t count = 0;
	std::deque<std::deque<unsigned int> > lower;
	fJ_impl(deq, deq.size(), count, test_mode, 0);
	std::cout << "comparisons: " << count << std::endl;
	return count;
}

size_t fordJohnsonSort(std::list<unsigned int>& list, bool test_mode) {
	size_t count = 0;
	(void)list;
	(void)test_mode;
	return count;
}
