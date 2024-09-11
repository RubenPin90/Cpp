#include "Intern.hpp"
#define AMOUNT 3

Intern::Intern() {
	std::cout << "Intern Constructor was called." << std::endl;
}

Intern::Intern(const Intern& ref) {
	std::cout << "Intern Copy Constructor was called." << std::endl;
	*this = ref;
}

Intern::~Intern() {
	std::cout << "Intern Deconstructor was called." << std::endl;
}

Intern& Intern::operator=(const Intern& rhs) {
	std::cout << "Intern Assignment operator overload was called." << std::endl;
	(void)rhs;
	return(*this);
}

AForm* Intern::makeForm(std::string form_name, std::string form_target) const {
	static const std::string formName[AMOUNT] = {"SC", "RR", "PP"};
	static const _createFormPtr forms[AMOUNT] = {&Intern::_createSCForm, &Intern::_createRRForm, &Intern::_createPPForm};

	for (int i = 0; i < AMOUNT; i++)
		if (form_name == formName[i])
			return (this->*forms[i])(form_target);
	throw FormNotExistentException();
	return NULL;
}

const char* Intern::FormNotExistentException::what() const throw() {
	return ("Sorry, there is no Form with this Name.");
}

AForm* Intern::_createSCForm(const std::string& target) const {
	std::cout << "Intern creates a ShrubberyCreationForm with target: " << target << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm* Intern::_createRRForm(const std::string& target) const {
	std::cout << "Intern creates a RobotomyRequestForm with target: " << target << std::endl;
	return new RobotomyRequestForm(target);
}

AForm* Intern::_createPPForm(const std::string& target) const {
	std::cout << "Intern creates a PresidentialPardonForm with target: " << target << std::endl;
	return new PresidentialPardonForm(target);
}