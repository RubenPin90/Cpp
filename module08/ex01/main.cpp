#include "Span.hpp"

void print(std::vector<int> &vec) { 
	std::cout << "Capacity of vector without reallocation: " << vec.capacity() << std::endl;
	std::cout << "Content of vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) 
	{ std::cout << *it << " "; }
	std::cout << "\n";
}

int main() {
	{
		std::cout <<"\n+++++++++++++++Test1 - Create Span++++++++++++++++\n\n";
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout <<"\n+++++++++++++++Test2 - Not enough elements Error++++++++++++++++\n\n";
		Span sp = Span(1);
		try {
			sp.addNumber(12);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch(std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout <<"\n+++++++++++++++Test3 - Span full Error++++++++++++++++\n\n";
		try {
			sp.addNumber(15);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch(std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout <<"\n+++++++++++++++Test4 - Error addMulti++++++++++++++++\n\n";
		std::vector<int> vec(1, 0);
		print(vec);
		Span sp = Span(vec.size());
		for (int i = 0; i < 4; ++i) {
			vec.push_back(std::rand() % 10);
			print(vec);
		}
		try {
			sp.addMulti(vec.begin(), vec.end());
		} catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout <<"\n+++++++++++++++Test4 - addMulti++++++++++++++++\n\n";
		int arr[] = {3, 4, 5};
		std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
		print(vec);
		Span sp(vec.size());
		try {
			sp.addMulti(vec.begin(), vec.end());
		} catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
