#include "RPN.hpp"

int FilterWrongInput(int ac, char* av[]) {
	if (ac < 2) {
		std::cerr << "Error: Wrong Usage!" << std::endl;
		std::cerr << "Usage: " << av[0] << " \"n amount of numbers + (n - 1 amount of operators)\"" << std::endl;
		return FAIL;
	} else if (ac > 2) {
		std::cerr << "Error: Wrong Usage!" << std::endl;
		std::cerr << "Too many Arguments, counted: " << ac - 1 << std::endl;
		std::cerr << "Don't forget the quotes!" << std::endl;
		std::cerr << "\nUsage: " << av[0] << " \"n amount of numbers + (n - 1 amount of operators)\"" << std::endl;
		return FAIL;
	}
	return SUCCESS;
}

int main(int ac, char* av[]) {
	if (FilterWrongInput(ac, av))
		return FAIL;
	try {
		RPN calc(av[1]);
	} catch(std::exception &e) {
		std::cerr << "ERROR: " <<e.what() << std::endl;
		return FAIL;
	}
	return SUCCESS;
}
