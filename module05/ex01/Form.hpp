
#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& ref);
		~Form();
		Form&	operator=(const Form& rhs);

		bool	getBool() const;
		std::string getName() const;
		int		getSignGrade() const;
		int		getExecGrade() const;

		void beSigned(const Bureaucrat ref);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	
	private:
		const std::string 	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;
};

std::ostream& operator<<(std::ostream& ost, const Form& rhs);


#endif