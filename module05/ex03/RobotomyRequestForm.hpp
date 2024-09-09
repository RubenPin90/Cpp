#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <cstdlib>


class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

		void executeAction(const Bureaucrat& executor) const;

	private:
		std::string _target;
};

//Alias for convenience but unfortunately only in C++11
// using RRForm = RobotomyRequestForm;

std::ostream& operator<<(std::ostream& ost, const RobotomyRequestForm& rhs);

#endif
