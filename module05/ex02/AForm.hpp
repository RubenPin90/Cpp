
#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm& ref);
		virtual ~AForm();
		AForm&	operator=(const AForm& rhs);

		bool	getBool() const;
		std::string getName() const;
		int		getSignGrade() const;
		int		getExecGrade() const;

		void	beSigned(const Bureaucrat ref);
		void	execute(const Bureaucrat& executor) const;
		virtual void executeAction(const Bureaucrat& exec) const = 0;

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

std::ostream& operator<<(std::ostream& ost, const AForm& rhs);


#endif
