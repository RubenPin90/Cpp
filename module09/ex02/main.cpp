#include "PmergeMe.hpp"

int FilterWrongInput(int ac, char* av[]) {
	if (ac < 2) {
		std::cerr << "Error: Wrong Usage!" << std::endl;
		std::cerr << "Usage: " << av[0] << " [positive integer sequence to be sorted]" << std::endl;
		return FAIL;
	}
	return SUCCESS;
}
int main(int ac, char *av[]) {
	if (FilterWrongInput(ac, av))
		return FAIL;
	try {

	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
		return FAIL;
	}
	return SUCCESS;
}
