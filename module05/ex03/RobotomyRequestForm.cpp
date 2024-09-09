#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
	std::cout << "RobotomyRequestForm Constructor was called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm Constructor2 was called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : AForm(ref), _target(ref._target) {
	std::cout << "RobotomyRequestForm Copy Constructor was called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm Deconstructor was called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	std::cout << "RobotomyRequestForm Assignment operator overload was called." << std::endl;
	if (this != &rhs) {
		this->_target = rhs._target;
		AForm::operator=(rhs);
	}
	return(*this);
}

void RobotomyRequestForm::executeAction(const Bureaucrat& executor) const {
	std::cout << "*Loud Drilling Noise*" << std::endl;
	if ((rand() % 100) > 50)
		std::cout << _target << " has been robotomized successfully by " << executor.getName() << std::endl;
	else
		std::cout << "Robotomy on " << _target << " failed." << std::endl;
}

std::ostream& operator<<(std::ostream& ost, const RobotomyRequestForm& RRForm) {
	ost << "RRForm: " << RRForm.getName() << std::endl;
	ost << "Sign Status: " << RRForm.getBool() << std::endl;
	ost << "Signing Grade: " << RRForm.getSignGrade() << std::endl;
	ost << "Execute Grade: " << RRForm.getExecGrade() << std::endl;
	return (ost);
}
