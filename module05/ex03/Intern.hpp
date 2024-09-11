#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& ref);
		~Intern();
		Intern& operator=(const Intern& rhs);
		AForm* makeForm(std::string form_name, std::string form_target) const;

		class FormNotExistentException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		typedef AForm* (Intern::*_createFormPtr)(const std::string&) const;
		AForm* _createSCForm(const std::string& target) const;
		AForm* _createRRForm(const std::string& target) const;
		AForm* _createPPForm(const std::string& target) const;
};



#endif
