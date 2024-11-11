#include "BitcoinExchange.hpp"

int main (int ac, char* av[]) {
	if (ac < 2 || ac > 3) {
		std::cerr << "Error: Could not open file." << std::endl;
		std::cerr << "Usage: " << av[0] << " <existing_input_file.txt> [optional_database_file.csv]" << std::endl;
		return FAIL;
	}
	try {
		if (ac == 2) {
			std::cout << "Input: " << av[1] << " | Database: default" << std::endl;
			BitcoinExchange BitEx(av[1]);
			// std::cout << BitEx;
		}
		else if (ac == 3) {
			std::cout << "Input: " << av[1] << " | Database: " << av[2] << std::endl;
			BitcoinExchange BitEx(av[1], av[2]);
		}
	} catch(std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return FAIL;
	}
	return SUCCESS;
}
