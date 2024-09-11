#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(LOWEST) {
	std::cout << "Default Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(LOWEST) {
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	std::cout << "Bureaucrat Constructor 2 called" << std::endl;
	_checkGrade(grade);
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : _name(ref._name) {
	std::cout << getName() << " Copy Constructor called" << std::endl;
	*this = ref;
}

Bureaucrat::~Bureaucrat() {
	std::cout << getName() << " Deconstructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	std::cout << "Bureaucrat Overload function of assignment operator called." << std::endl;
	if (this != &rhs) {
		_grade = rhs.getGrade();
	}
	return (*this);
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::_checkGrade(int newvalue) const {
	if (newvalue < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (newvalue > LOWEST)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decrementGrade() {
	_checkGrade(this->_grade + 1);
	this->_grade += 1;
}

void Bureaucrat::incrementGrade() {
	_checkGrade(this->_grade - 1);
	this->_grade -= 1;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		bool tmp = form.getBool();
		form.beSigned(*this);
		if (form.getBool() != tmp)
			std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}

}

void Bureaucrat::executeForm(const AForm& form) {
	try {
			form.execute(*this);
	}
	catch (std::exception &e) {
		std::cerr << _name << " could't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is higher than highest grade (1).");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is lower than lowest grade (150).");
}

std::ostream& operator<<(std::ostream& ost, const Bureaucrat& rhs) {
	ost << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (ost);
}
