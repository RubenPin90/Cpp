#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

		void executeAction(const Bureaucrat& executor) const;

	private:
		std::string _target;
};

//Alias for convenience but unfortunately only in C++11
// using PPForm = PresidentialPardonForm;

std::ostream& operator<<(std::ostream& ost, const PresidentialPardonForm& rhs);

#endif
