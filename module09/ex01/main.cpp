#include "RPN.hpp"
#include <cstring>

void tester() {
	
	std::cout << "+++++++++++++ TEST CASES +++++++++++++++" << std::endl;

	std::pair<std::string, int> test_cases[] = {
		std::make_pair("8 9 * 9 - 9 - 9 - 4 - 1 +", 42),
		std::make_pair("9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -", 42),
		std::make_pair("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 / ", 15),
		std::make_pair("-2 3 +", 1),
		std::make_pair("5 2 2 * * 9 + 7 6 9 * - + 5 /", -3),
		std::make_pair("23 +", -1),
		std::make_pair("(3 - 2)", -1),
		std::make_pair("* 3 8 ", -1),
		std::make_pair("5 0 / ", -1),
		std::make_pair("9 9 9 9 9 9 9 9 9 * * * * * * * * 9 *", -1),
	};
	std::size_t arr_size = sizeof(test_cases) / sizeof(test_cases[0]);
	for (std::size_t i = 0; i < arr_size; ++i) {
		try {
			std::cout << i << ". Testcase: " << "[ " << test_cases[i].first << " ]:  ";
			RPN calc(test_cases[i].first);
			if (calc.getResult() != test_cases[i].second) {
				std::cout << "FAIL" << std::endl;
			} else {
				std::cout << "OK" << std::endl;
			}
		} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
		}
	}
}

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
	if (!std::strcmp(av[1], "tests")) {
		tester();
		return SUCCESS;
	}
	try {
		RPN calc(av[1]);
	} catch(std::exception &e) {
		std::cerr << "ERROR: " <<e.what() << std::endl;
		return FAIL;
	}
	return SUCCESS;
}
