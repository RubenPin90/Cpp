#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <stdexcept>
#include <fstream>

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

		void executeAction(const Bureaucrat& executor) const;

	private:
		std::string _target;
		const std::string	_asciiTree() const ;
};

//Alias for convenience but unfortunately only in C++11
// using SCForm = ShrubberyCreationForm;
std::ostream& operator<<(std::ostream& ost, const ShrubberyCreationForm& rhs);

#endif
