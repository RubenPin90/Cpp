#include "easyfind.hpp"

int main () {
	int arr[] = {1, 2, 3, 4, 5};
	{
		std::cout << "++++++++++++++++++++++Vector test++++++++++++++++++++++++++\n";
		std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
		try {
			for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
				std::cout << "Trying to find: " << *it << std::endl;
				std::cout << "Value: " << *easyfind(vec, *it) << " was found int vector.\n";
			}
			std::cout << "Trying to find: " << "6" << std::endl;
			std::cout << "Value: " << *easyfind(vec, 6) << " was found int vector.\n";
		} catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
			}
	}
	{
		std::cout << "\n++++++++++++++++++++++Const Vector test++++++++++++++++++++++++++\n";
		const std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
		try {
			for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
				std::cout << "Trying to find: " << *it << std::endl;
				std::cout << "Value: " << *easyfind(vec, *it) << " was found int vector.\n";
			}
			std::cout << "Trying to find: " << "6" << std::endl;
			std::cout << "Value: " << *easyfind(vec, 6) << " was found int vector.\n";
		} catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}