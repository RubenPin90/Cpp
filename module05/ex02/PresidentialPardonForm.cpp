#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {
	std::cout << "PresidentialPardonForm Constructor was called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm Constructor2 was called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : AForm(ref), _target(ref._target) {
	std::cout << "PresidentialPardonForm Copy Constructor was called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm Deconstructor was called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	std::cout << "PresidentialPardonForm Assignment operator overload was called." << std::endl;
	if (this != &rhs) {
		this->_target = rhs._target;
		AForm::operator=(rhs);
	}
	return(*this);
}

void PresidentialPardonForm::executeAction(const Bureaucrat& executor) const {
	(void)executor;
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream& operator<<(std::ostream& ost, const PresidentialPardonForm& PPForm) {
	ost << "PPForm: " << PPForm.getName() << std::endl;
	ost << "Sign Status: " << PPForm.getBool() << std::endl;
	ost << "Signing Grade: " << PPForm.getSignGrade() << std::endl;
	ost << "Execute Grade: " << PPForm.getExecGrade() << std::endl;
	return (ost);
}
