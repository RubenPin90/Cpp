
#include "Form.hpp"

Form::Form() : _name("default"), _signGrade(HIGHEST), _execGrade(HIGHEST), _signed(false) {
	std::cout << "Default Form Constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), 
															_execGrade(execGrade), _signed(false) {
	std::cout << "Form Constructor called" << std::endl;
	if (signGrade < HIGHEST || execGrade < HIGHEST)
		throw(Bureaucrat::GradeTooHighException());
	if (signGrade > LOWEST || execGrade > LOWEST)
		throw(Bureaucrat::GradeTooLowException());
}

Form::Form(const Form& ref) : _name(ref._name + "-copy"), _signGrade(ref._signGrade), 
										_execGrade(ref._execGrade), _signed(ref._signed) {
	std::cout << "Form Constructor called" << std::endl;
	*this = ref;
}

Form::~Form() {
	std::cout << "Form Deconstructor called" << std::endl;
}

Form& Form::operator=(const Form& rhs) {
	if (this != &rhs)
		_signed = rhs.getBool();
	return (*this);
}

bool Form::getBool() const {
	return (_signed);
}

std::string Form::getName() const {
	return(_name);
}

int Form::getSignGrade() const {
	return (_signGrade);
}

int Form::getExecGrade() const {
	return (_execGrade);
}

void Form::beSigned(const Bureaucrat ref) {
	if (ref.getGrade() > getSignGrade())
		throw(Form::GradeTooLowException());
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Aborting..Grade is too high for this form.");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Aborting..Grade is too low for this form.");
}

std::ostream& operator<<(std::ostream& ost, const Form& form) {
	ost << "Form: " << form.getName() << std::endl;
	ost << "Sign Status: " << form.getBool() << std::endl;
	ost << "Signing Grade: " << form.getSignGrade() << std::endl;
	ost << "Execute Grade: " << form.getExecGrade() << std::endl;
	return (ost);
}


