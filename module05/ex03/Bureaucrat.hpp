#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "AForm.hpp"
#include <iostream>
#define HIGHEST 1
#define LOWEST 150

class AForm;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& ref);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& rhs);
		std::string getName() const;
		int 		getGrade() const;
		void		decrementGrade();
		void 		incrementGrade();
		void 		signForm(AForm& form);
		void		executeForm(const AForm& form);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		int					_grade;
		void				_checkGrade(int newvalue) const;
};

std::ostream& operator<<(std::ostream& ost, const Bureaucrat& rhs);

#endif
