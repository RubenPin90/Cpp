#ifndef FORDJOHNSONSORT_HPP
#define FORDJOHNSONSORT_HPP
#include "PmergeMe.hpp"
#include <vector>

typedef struct s_data {
	std::size_t c_size;
	std::size_t block_size;
	std::size_t blocks;
	bool test_mode;
} t_data;


size_t fordJohnsonSort(std::deque<unsigned int>& deq, bool check);
size_t fordJohnsonSort(std::list<unsigned int>& list, bool check);


#endif
