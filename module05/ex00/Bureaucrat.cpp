#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default") {

}

Bureaucrat::Bureaucrat(std::string name) : _name(name) {

}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : _name(ref._name) {

}

Bureaucrat::~Bureaucrat() {

}