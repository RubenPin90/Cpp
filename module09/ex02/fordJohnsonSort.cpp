#include "fordJohnsonSort.hpp"

typedef std::deque<unsigned int>::iterator deqIt;
typedef std::list<unsigned int>::iterator listIt;

template <typename T>
void prnt(const std::string& str, const T& value, const bool test_mode) {
	if (test_mode)
		std::cout << str << value << std::endl; 
}


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

//Implementation of Ford-Johnson Algorithm within the same container.
//Container is sorted by (it, it + n), where n is the current level and size of the blocks being sorted.
void fJ_impl(std::deque<unsigned int>& deq, const size_t size, size_t& comp, bool test_mode, size_t lvl) {
	(void)test_mode;
	// left bitwise shift of 1 by n, equivalent to 2^n. 
	// block_size is increasing in that range by each level.
	size_t c_size = 1 << lvl;
	size_t block_size = c_size * 2;
	size_t blocks = size / block_size;

	prnt("\nLEVEL: ", lvl, test_mode);
	// End recursion if no blocks fit into container size.
	if (!blocks) {
		prnt("Last level detected: ", "Exiting", test_mode);
		return;
	}
	size_t odd = size % block_size;
	deqIt newend = deq.end();
	if (odd)
		newend = deq.end() - odd;
	for (deqIt it = deq.begin(); it != newend; it += block_size) {
		if (*it < *(it + c_size)) {
			std::cout << "before swap " << *it << " - " << *(it + c_size) << std::endl;
			std::swap_ranges(it, it + c_size, it + c_size);
			std::cout << "after swap " << *it << " - " << *(it + c_size) << std::endl;
		}
		comp++;
	}
	std::cout << "\ndeq: ";
	for(deqIt it = deq.begin(); it != deq.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	fJ_impl(deq, deq.size(), comp, test_mode, ++lvl);

	std::deque<unsigned int> tmp, result, struggler;
	tmp = deq;
	result.insert(result.end(), tmp.begin(), tmp.begin() + c_size);
	tmp.erase(tmp.begin(), tmp.begin() + c_size);
	result.insert(result.begin(), tmp.begin(), tmp.begin() + c_size);
	tmp.erase(tmp.begin(), tmp.begin() + c_size);

	for (deqIt it = tmp.begin(); it != tmp)
	std::cout << "\nresult after lvl " << lvl << ": ";
	for (deqIt it = result.begin(); it != result.end(); ++it) {
    	std::cout << *it << " ";
	}
	// if (size % 2 != 0) {
	// 	deqIt it = std::lower_bound(result.begin(), result.end(), struggler);
	// 	result.insert(it, struggler);
	// }

	// std::cout << "\nresult: ";
	// for(deqIt it = result.begin(); it != result.end(); ++it) {
	// 	std::cout << *it << " ";
	// }
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
