#include "PmergeMe.hpp"
#include <cstring>

int FilterWrongInput(int ac, char* av[]) {
	if (ac < 2) {
		std::cerr << "Error: Wrong Usage!" << std::endl;
		std::cerr << "\n***************************" << std::endl;
		std::cerr << "Usage:\t\t" << av[0] << " [positive integer sequence]" << std::endl;
		std::cerr << "Run test mode:\t" << av[0] << " -t [positive integer sequence]" << std::endl;
		std::cerr << "***************************\n" << std::endl;
		return FAIL;
	}
	return SUCCESS;
}
int main(int ac, char *av[]) {
	if (FilterWrongInput(ac, av))
		return FAIL;
	bool test_mode = false;
	if (!std::strcmp(av[1], "-t")) {
		 test_mode = true;
		for (int i = 1; i < ac - 1; ++i) {
			av[i] = av[i + 1];
		}
		--ac;
	}
	try {
		PmergeMe purgeMe(ac, av);
		purgeMe.sortList(test_mode);
		purgeMe.sortDeque(test_mode);
	} catch(std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return FAIL;
	}
	return SUCCESS;
}
