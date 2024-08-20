#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat ruben("Ruben", 25);
	Bureaucrat daniel("Daniel", 2);
	Bureaucrat sloth("Sloth", 78);
	Bureaucrat sloth2(sloth);

	Form unnamed = Form();
	Form f1("f1", 2, LOWEST);
	Form f2("f2", 30, LOWEST);
	Form f3("f3", 78, LOWEST);
	try {
		Form f4("f4", 156, LOWEST);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Signing the forms:" << std::endl;
	try {
		sloth2.signForm(unnamed);
		ruben.signForm(f2);
		daniel.signForm(f1);
		sloth.signForm(f3);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}