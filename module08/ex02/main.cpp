#include "MutantStack.hpp"
#include <list>
#include <ctime>
#include <cstdlib>

int main() {
{
	std::cout << "++++++++++++++++ Test from Subject +++++++++++++++++++\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "beginning of stack: " << *it << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
}
{
	std::cout << "++++++++++++++++ Comparison test with list +++++++++++++++++++\n";
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator it = lst.begin();
	std::cout << "beginning of list: " << *it << std::endl;
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
}
{
	std::cout << "++++++++++++++++ Test - Const Iterator +++++++++++++++++++\n";
	MutantStack<unsigned int> stack;
	srand(time(0));
	for (int i = 0; i < 10; ++i) {
		stack.push(rand() % 100);
	}
	MutantStack<unsigned int>::const_iterator cit = stack.begin();
	MutantStack<unsigned int>::const_iterator cite = stack.end();
	while (cit != cite) {
		std::cout << *cit << " - ";
		++cit;
	}
	std::cout << "END\n";
}
{ 
	std::cout << "\n++++++++++++++++ Test - Use Iterator +++++++++++++++++++\n";
	MutantStack<std::string> text_stack;
	text_stack.push("Hello");
	text_stack.push("World");
	MutantStack<std::string>::iterator it = text_stack.begin();
	MutantStack<std::string>::const_iterator cit = text_stack.begin();
	MutantStack<std::string>::iterator ite = text_stack.end();
	MutantStack<std::string>::const_iterator cite = text_stack.end();
	try {
		*it += " Crazy ";
		for (; it != ite; ++it) {
			std::cout << *it;
		}
		std::cout << std::endl;
		it = text_stack.begin();
		++it;
		*it += "!";
		for (; cit != cite; ++cit) {
			// Can't modify *cit += " " since cit is a const_iterator;
			std::cout << *cit;
		}
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
return 0;
}
