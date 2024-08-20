#include "Bureaucrat.hpp"

int main(void) {
	{
	try {
		Bureaucrat sloth("sloth", 10);
		std::cout << sloth << std::endl;
		for(int i = 0; ; i++) {
			sloth.incrementGrade();
			std::cout << sloth << std::endl;
		}
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << "An error occurred: " << e.what() << std::endl;
	}
	}
	std::cout << "============================" << std::endl;
	{
	try {
		Bureaucrat daniel("daniel", 151);
		std::cout << daniel << std::endl;
	}
	catch(std::exception& e) {
		std::cerr << "An error occurred: " << e.what() << std::endl;
	}
	}
	std::cout << "============================" << std::endl;
	{
	try {
		Bureaucrat ruben("ruben");
		std::cout << ruben << std::endl;
		ruben.incrementGrade();
		std::cout << ruben << std::endl;
		ruben.decrementGrade();
		std::cout << ruben << std::endl;
	}
	catch(std::exception& e) {
		std::cerr << "An error occurred: " << e.what() << std::endl;
	}
	}
}