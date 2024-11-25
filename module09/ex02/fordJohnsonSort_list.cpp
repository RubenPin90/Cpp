#include "fordJohnsonSort.hpp"

typedef std::list<unsigned int>::iterator listIt;


void prnt_cont(const std::string& description, const int& lvl, std::list<unsigned int>& cont, const bool test_mode, const std::size_t& c_size) {
	if (test_mode) {
		std::ostringstream ost;
		ost << "\n" << description << " lvl " << lvl << ": ";
		rp_tools::prnt("", ost.str(), test_mode);
		rp_tools::printContainer(cont, c_size);
	}
}

listIt binary_find(std::list<unsigned int>& a_row,  const unsigned int val, const t_data& info, const std::size_t& n, std::size_t& comp) {
	std::size_t range = std::min(static_cast<std::size_t>((1 << n) - 1), a_row.size() / info.c_size);
	listIt first = a_row.begin();
	listIt last = first;
	std::advance(last, info.c_size * range);

	listIt it;
	std::size_t count = std::distance(first, last) / info.c_size;
	std::size_t step;

	while (count > 0) {
		it = first;
		step = count / 2;
		if (static_cast<std::size_t>(std::distance(it, last)) < step * info.c_size)
            break;
		std::advance(it, step * info.c_size);

		std::cout << *it << "<" << val << "\n";
		if (*it < val) {
			if (static_cast<std::size_t>(std::distance(it, last)) < info.c_size)
                break;
			std::advance(first, (step + 1) * info.c_size);
			count -= step + 1;
		} else {
			count = step;
		}
		comp++;
	}
	return first; 
}

void list_swap(std::list<unsigned int>& lst, const t_data& info, std::size_t& comp) {
	listIt lsc_begin = lst.begin();
	listIt lsc_end = lsc_begin;
	std::advance(lsc_end, info.c_size);

	listIt rsc_begin = lsc_end;
	listIt rsc_end = rsc_begin;
	std::advance(rsc_end, info.c_size);
	
	for (std::size_t i = 0; i < info.blocks; ++i) {
		if (*lsc_begin < *rsc_begin) {
			rp_tools::prnt("Swaping ", *lsc_begin, info.test_mode);
			lst.splice(lsc_begin, lst, rsc_begin, rsc_end);
			std::swap(lsc_begin, rsc_begin);
		}
		std::advance(lsc_begin, info.block_size);
		std::advance(lsc_end, info.block_size);
		std::advance(rsc_begin, info.block_size);
		std::advance(rsc_end, info.block_size);
		comp++;
	}
}

void sort_lns(std::list<unsigned int>& lst, std::list<unsigned int>& a, std::list<unsigned int>& b, const t_data& info) {
	bool alternate = true;
	std::list<unsigned int> tmp;
	listIt it = lst.begin();
	// std::size_t chunks = lst.size() / info.c_size;
	// std::cout << "blocks: " << info.blocks << "\n";
	// std::cout << "c_size: " << info.c_size << "\n";
	for (std::size_t i = 0; i <= info.blocks; ++i) {
		listIt next = it;
		std::cout << "next: " << *next << "\n";
		std::advance(next, info.c_size);
		if(alternate) {
			a.splice(a.end(), lst, it, next);
			std::cout << "a\n";
		} else {
			b.splice(b.end(), lst, it, next);
			std::cout << "b\n";
		}
		alternate = !alternate;
		it = next;
	}
	if (!lst.empty()) {
		b.splice(b.end(), lst);
	}
}

listIt next_iter(listIt lst, const std::size_t& steps) {
	std::advance(lst, steps);
	return lst;
}

//Implementation of Ford-Johnson Algorithm with std::list.
//Container is sorted by (it, it + n), where n is the current level and size of the blocks being sorted.
void fJ_impl(std::list<unsigned int>& lst, const std::size_t size, std::size_t& comp, bool check, std::size_t lvl) {
	// left bitwise shift of 1 by n, equivalent to 2^n. 
	// block_size is increasing in that range by each level.
	t_data info;
	info.c_size = 1 << lvl;
	info.block_size = info.c_size * 2;
	info.blocks = size / info.block_size;
	info.test_mode = check;	

	rp_tools::prnt("\nLEVEL: ", lvl, info.test_mode);
	prnt_cont("My list at start", lvl, lst, info.test_mode, info.c_size);
	// End recursion if no blocks fit into container size.
	if (!info.blocks) {
		rp_tools::prnt("Last level detected: ", "Exiting", info.test_mode);
		return;
	}
	std::size_t odd = size % info.block_size;
	listIt newend = lst.end();
	if (odd) {
		listIt tmp = lst.begin();
		std::advance(tmp, size - odd);
		newend = tmp;
	}
	list_swap(lst, info, comp);
	prnt_cont("My list after swap at", lvl, lst, info.test_mode, info.c_size);

	fJ_impl(lst, lst.size(), comp, info.test_mode, lvl + 1);

	std::list<unsigned int> a_row, b_row;
	sort_lns(lst, a_row, b_row, info);

	listIt next = b_row.begin();
	std::advance(next, info.c_size);
	b_row.splice(a_row.begin(), b_row, b_row.begin(), next);

	prnt_cont("a_row", lvl, a_row, info.test_mode, info.c_size);
	prnt_cont("b_row", lvl, b_row, info.test_mode, info.c_size);

	listIt b_it = b_row.begin();
	std::size_t n = 2;
	while (b_it != b_row.end()) {
		std::size_t remaining = std::distance(b_it, b_row.end());
		std::size_t c_count = remaining / info.c_size;
		if (!c_count) {
			a_row.insert(a_row.end(), b_it, b_row.end());
			break;
		}
		//calculating jt-steps per n
		std::size_t jt_steps = rp_tools::gen_jacobsthal(n + 1) - rp_tools::gen_jacobsthal(n);
		jt_steps = std::min(jt_steps, c_count);

		for (int i = jt_steps; i != 0; --i) {
			listIt tmp = b_it;
			std::advance(tmp, (i - 1) * info.c_size);
			listIt ins_pos = binary_find(a_row, *tmp, info, n, comp);
			std::cout << "ins_pos: " << *ins_pos << std::endl;
			listIt next_tmp = tmp;
			std::advance(next_tmp, info.c_size);
			a_row.splice(ins_pos, b_row, tmp, next_tmp);
			// a_row.splice(ins_pos, b_row, tmp, next_iter(tmp, info.c_size));
			prnt_cont("New list at", lvl, lst, info.test_mode, info.c_size);
			b_it = b_row.begin();
		}
		n++;
	}
	lst = a_row;
	prnt_cont("New list at", lvl, lst, info.test_mode, info.c_size);
}

std::size_t fordJohnsonSort(std::list<unsigned int>& list, bool test_mode) {
	std::size_t count = 0;
	fJ_impl(list, list.size(), count, test_mode, 0);
	return count;
}
