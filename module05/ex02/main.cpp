#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	Bureaucrat ruben("Ruben", 25);
	Bureaucrat daniel("Daniel", 2);
	Bureaucrat sloth("Sloth", 78);
	Bureaucrat sloth2(sloth);

	std::cout << "++++++++++TEST 1++++++++++\n";
	ShrubberyCreationForm SCForm("test");
	try {
		std::cout << "sign:\n";
		sloth.signForm(SCForm);
		std::cout << "execute:\n";
		sloth.executeForm(SCForm);
		std::cout << "+++++++++++++++++++++\n";
		std::cout << "sign:\n";
		daniel.signForm(SCForm);
		std::cout << "execute:\n";
		daniel.executeForm(SCForm);
		std::cout << "+++++++++++++++++++++\n";
		std::cout << "sign:\n";
		ruben.signForm(SCForm);
		std::cout << "execute:\n";
		ruben.executeForm(SCForm);
		std::cout << "\n";
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "++++++++++TEST 2++++++++++\n";
	RobotomyRequestForm RRForm("test");
	try {
		std::cout << "sign:\n";
		sloth.signForm(RRForm);
		std::cout << "execute:\n";
		sloth.executeForm(RRForm);
		std::cout << "+++++++++++++++++++++\n";
		std::cout << "sign:\n";
		daniel.signForm(RRForm);
		std::cout << "execute:\n";
		daniel.executeForm(RRForm);
		std::cout << "+++++++++++++++++++++\n";
		std::cout << "sign:\n";
		ruben.signForm(RRForm);
		std::cout << "execute:\n";
		ruben.executeForm(RRForm);
		std::cout << "\n";
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "++++++++++TEST 3++++++++++\n";
	PresidentialPardonForm PPForm("test");
	try {
		std::cout << "sign:\n";
		sloth.signForm(PPForm);
		std::cout << "execute:\n";
		sloth.executeForm(PPForm);
		std::cout << "+++++++++++++++++++++\n";
		std::cout << "sign:\n";
		daniel.signForm(PPForm);
		std::cout << "execute:\n";
		daniel.executeForm(PPForm);
		std::cout << "+++++++++++++++++++++\n";
		std::cout << "sign:\n";
		ruben.signForm(PPForm);
		std::cout << "execute:\n";
		ruben.executeForm(PPForm);
		std::cout << "\n";
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
