#include "Span.hpp"

int main() {
	std::cout <<"\n+++++++++++++++Test1 - Create Span++++++++++++++++\n\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	{
		std::cout <<"\n+++++++++++++++Test2 - Error++++++++++++++++\n\n";
		try {
			Span sp = Span(4);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch(std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}