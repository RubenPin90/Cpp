#ifndef FORDJOHNSONSORT_HPP
#define FORDJOHNSONSORT_HPP
#include "PmergeMe.hpp"
#include <vector>

typedef struct s_data {
	std::size_t c_size;
	std::size_t block_size;
	std::size_t blocks;
	std::size_t chunks;
	bool test_mode;
} t_data;


std::size_t fordJohnsonSort(std::deque<unsigned int>& deq, bool check);
std::size_t fordJohnsonSort(std::list<unsigned int>& list, bool check);


#endif
