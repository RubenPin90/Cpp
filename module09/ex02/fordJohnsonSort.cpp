#include "fordJohnsonSort.hpp"
#include <vector>

typedef std::deque<unsigned int>::iterator deqIt;
typedef std::list<unsigned int>::iterator listIt;


void prnt_cont(const std::string& description, const int& lvl, std::deque<unsigned int>& cont, const bool test_mode, const size_t& c_size) {
	if (test_mode) {
		std::ostringstream ost;
		ost << "\n" << description << " lvl " << lvl << ": ";
		rp_tools::prnt("", ost.str(), test_mode);
		rp_tools::printContainer(cont, c_size);
	}
}

deqIt binary_find(std::deque<unsigned int>& a_row,  const unsigned int val, const std::size_t c_size, const size_t& n, size_t& comp) {
	size_t range = std::min(static_cast<size_t>((1 << n) - 1), a_row.size() / c_size);
	deqIt first = a_row.begin();
	deqIt last = first + c_size * range;
	deqIt it;
	std::cout << "Range for n = " << n << ": " << range << std::endl;

	size_t count = std::distance(first, last) / c_size;
	size_t step;

	while (count > 0) {
		it = first;
		step = count / 2;
		std::cout << "It " << *it << std::endl;
		std::cout << "Val " << val << std::endl;
		std::cout << "Step " << step << std::endl;
		if (static_cast<std::size_t>(std::distance(it, last)) < step * c_size) {
            std::cout << "Out-of-bounds attempt detected. Stopping..." << std::endl;
            break;
        }
		std::advance(it, step * c_size);
		std::cout << "Current It = " << *it << std::endl;

		if (*it < val) {
			if (static_cast<std::size_t>(std::distance(it, last)) < c_size) {
                std::cout << "Cannot advance further. Breaking..." << std::endl;
                break;
            }
			std::advance(first, (step + 1) * c_size);
			count -= step + 1;
		} else {
			count = step;
		}
		comp++;
	}
	return first; 
}

// J(n) = J(n-1) + 2 * J(n-2)
size_t gen_jacobsthal(size_t num) {
	if(num == 0)
		return 0;
	if(num == 1)
		return 1;
	return gen_jacobsthal(num - 1) + 2 * gen_jacobsthal(num - 2);
}


//Implementation of Ford-Johnson Algorithm within the same container.
//Container is sorted by (it, it + n), where n is the current level and size of the blocks being sorted.
void fJ_impl(std::deque<unsigned int>& deq, const size_t size, size_t& comp, bool test_mode, size_t lvl) {
	// left bitwise shift of 1 by n, equivalent to 2^n. 
	// block_size is increasing in that range by each level.
	size_t c_size = 1 << lvl;
	size_t block_size = c_size * 2;
	size_t blocks = size / block_size;

	rp_tools::prnt("\nLEVEL: ", lvl, test_mode);
	prnt_cont("My deq at start", lvl, deq, test_mode, c_size);
	// End recursion if no blocks fit into container size.
	if (!blocks) {
		rp_tools::prnt("Last level detected: ", "Exiting", test_mode);
		return;
	}
	size_t odd = size % block_size;
	deqIt newend = deq.end();
	if (odd) 
		newend = deq.end() - odd;
	for (deqIt it = deq.begin(); it != newend; it += block_size) {
		if (*it < *(it + c_size)) {
			rp_tools::prnt("Swaping ", *it, test_mode);
			std::swap_ranges(it, it + c_size, it + c_size);
		}
		comp++;
	}
	prnt_cont("My deq after swap at ", lvl, deq, test_mode, c_size);

	fJ_impl(deq, deq.size(), comp, test_mode, lvl + 1);

	std::deque<unsigned int> a_row, b_row;
	a_row.insert(a_row.end(), deq.begin(), deq.begin() + c_size);
	a_row.insert(a_row.begin(), deq.begin() + c_size, deq.begin() + block_size);

	bool alternate = true;
	for (deqIt it = deq.begin() + block_size; it != newend; it += c_size) {
		if (alternate)
			a_row.insert(a_row.end(), it, it + c_size);
		else
			b_row.insert(b_row.end(), it, it + c_size);
		alternate = !alternate;
	}
	if (odd) {
		b_row.insert(b_row.end(), newend, deq.end());
	}

	prnt_cont("a_row", lvl, a_row, test_mode, c_size);
	prnt_cont("b_row", lvl, b_row, test_mode, c_size);
	
	deqIt b_it = b_row.begin();
	size_t n = 2;
	while (b_it != b_row.end()) {
		size_t remaining = std::distance(b_it, b_row.end());
		size_t c_count = remaining / c_size;
		if (!c_count) {
			a_row.insert(a_row.end(), b_it, b_row.end());
			break;
		}
		//calculating jt-steps per n
		size_t jt_steps = gen_jacobsthal(n + 1) - gen_jacobsthal(n);
		jt_steps = std::min(jt_steps, c_count);

		for (int i = jt_steps; i != 0; i--) {
			deqIt tmp = b_it + (i - 1) * c_size;
			std::cout << "Pointer at " << *tmp << std::endl;
			deqIt ins_pos = binary_find(a_row, *tmp, c_size, n, comp);
			a_row.insert(ins_pos, tmp, tmp + c_size);
		}
		b_it += jt_steps * c_size;
		n++;
	}
	deq = a_row;
	prnt_cont("New deq at", lvl, deq, test_mode, c_size);
}

size_t fordJohnsonSort(std::deque<unsigned int>& deq, bool test_mode) {
	size_t count = 0;
	std::deque<std::deque<unsigned int> > lower;
	fJ_impl(deq, deq.size(), count, test_mode, 0);
	return count;
}

size_t fordJohnsonSort(std::list<unsigned int>& list, bool test_mode) {
	size_t count = 0;
	(void)list;
	(void)test_mode;
	return count;
}
