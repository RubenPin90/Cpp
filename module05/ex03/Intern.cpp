#include "Intern.hpp"

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
	return(*this);
}

AForm* makeForm(std::string form_name, std::string form_target) {
	
}