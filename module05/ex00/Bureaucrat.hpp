#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(const Bureaucrat& ref);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& rhs);
		getName();
		getGrade();
		DecrementGrade();
		IncrementGrade();

	private:
		std::string	_name;
		int			_grade;
};

#endif