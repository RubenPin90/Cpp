#include "RPN.hpp"

int main(int ac, char* av[]) {
	if (ac != 2) {
		std::cerr << "Error: Wrong Usage!" << std::endl;
		std::cerr << "Usage: " << av[0] << " \"n amount of numbers + (n - 1 amount of operators)\"" << std::endl;
	}
	try {
		RPN calc(av[1]);
	} catch(std::exception &e) {
		std::cerr << "ERROR: " <<e.what() << std::endl;
		return FAIL;
	}
	return SUCCESS;
}
