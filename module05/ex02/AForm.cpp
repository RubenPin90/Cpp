
#include "AForm.hpp"

AForm::AForm() : _name("default"), _signGrade(HIGHEST), _execGrade(HIGHEST), _signed(false) {
	std::cout << "Default AForm Constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), 
															_execGrade(execGrade), _signed(false) {
	std::cout << "AForm Constructor called" << std::endl;
	if (signGrade < HIGHEST || execGrade < HIGHEST)
		throw(Bureaucrat::GradeTooHighException());
	if (signGrade > LOWEST || execGrade > LOWEST)
		throw(Bureaucrat::GradeTooLowException());
}

AForm::AForm(const AForm& ref) : _name(ref._name + "-copy"), _signGrade(ref._signGrade), 
										_execGrade(ref._execGrade), _signed(ref._signed) {
	std::cout << "AForm Constructor called" << std::endl;
	*this = ref;
}

AForm::~AForm() {
	std::cout << "AForm Deconstructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs) {
	if (this != &rhs)
		_signed = rhs.getBool();
	return (*this);
}

bool AForm::getBool() const {
	return (_signed);
}

std::string AForm::getName() const {
	return(_name);
}

int AForm::getSignGrade() const {
	return (_signGrade);
}

int AForm::getExecGrade() const {
	return (_execGrade);
}

void AForm::beSigned(const Bureaucrat& ref) {
	if (ref.getGrade() > getSignGrade())
		throw(AForm::GradeTooLowException());
	if (_signed != true)
		_signed = true;
	else
		std::cout << "Form has already been signed!" << std::endl;
}

void AForm::execute(const Bureaucrat& executor) const {
	if(getBool() == false)
		throw(AForm::FormUnsignedException());
	if(executor.getGrade() > getExecGrade())
		throw(AForm::GradeTooLowException());
	executeAction(executor);
}

void AForm::executeAction(const Bureaucrat& executor) const {
	(void)executor;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Aborting..Grade is too high for this Form.");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Aborting..Grade is too low for this Form.");
}

const char* AForm::FormUnsignedException::what() const throw() {
	return ("Sorry! Form is not signed!");
}

std::ostream& operator<<(std::ostream& ost, const AForm& AForm) {
	ost << "AForm: " << AForm.getName() << std::endl;
	ost << "Sign Status: " << AForm.getBool() << std::endl;
	ost << "Signing Grade: " << AForm.getSignGrade() << std::endl;
	ost << "Execute Grade: " << AForm.getExecGrade() << std::endl;
	return (ost);
}
