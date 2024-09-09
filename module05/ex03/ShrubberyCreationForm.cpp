#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
	std::cout << "ShrubberyCreationForm Constructor was called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm Constructor2 was called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm(ref), _target(ref._target) {
	std::cout << "ShrubberyCreationForm Copy Constructor was called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm Deconstructor was called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	std::cout << "ShrubberyCreationForm Assignment operator overload was called." << std::endl;
	if (this != &rhs) {
		this->_target = rhs._target;
		AForm::operator=(rhs);
	}
	return(*this);
}

void ShrubberyCreationForm::executeAction(const Bureaucrat& executor) const {
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: There was a problem in creating file" + filename + ".");
	for (int i = 0; i < 3; i++) {
		file << _asciiTree(); 
	}
	file.close();
	std::cout << executor.getName() << " successfully created " << filename << " with ASCII trees inside!" << std::endl;
}

const std::string ShrubberyCreationForm::_asciiTree() const {

	const std::string tree = 
    "       _-_\n"
    "    /~~   ~~\\\n"
    " /~~         ~~\\\n"
    "{               }\n"
    " \\  _-     -_  /\n"
    "   ~  \\\\ //  ~\n"
    "_- -   | | _- _\n"
    "  _ -  | |   -_\n"
    "      // \\\\\n";
	return (tree);
}

std::ostream& operator<<(std::ostream& ost, const ShrubberyCreationForm& SCForm) {
	ost << "SCForm: " << SCForm.getName() << std::endl;
	ost << "Sign Status: " << SCForm.getBool() << std::endl;
	ost << "Signing Grade: " << SCForm.getSignGrade() << std::endl;
	ost << "Execute Grade: " << SCForm.getExecGrade() << std::endl;
	return (ost);
}
