#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void intro(Bureaucrat& sir) {
	std::cout << "\n------------THE BUREAUCRAT & HIS INTERN------------\n" << std::endl;
	std::cout << sir.getName() << ", a grizzled bureaucrat sits behind a cluttered desk.\n\
His office, dimly lit with flickering fluorescent lights, reeks of stale coffee and old leather.\n\
With a sigh, he presses the intercom button and grumbles, \"Send in the intern.\"\n" << std::endl;
	std::cout << "The door creaks open, and the intern, a wide-eyed and nervous young man, steps in, clutching a clipboard.\n" << std::endl;
	std::cout << "Without raising his head, the bureaucrat slides a stack of forms across the desk. \"I've got four special forms to process today,\"\n\
he grumbles. He finally looks up, his cold eyes narrowing.\n\
\"Think ya can handle it?”\n" << std::endl;
	std::cout << "The intern hesitates, confused by the forms and then says, \"Sure lets see.\"\n" << std::endl;
}

void ending(){
	std::cout << "The intern, shocked and anxious, stumbles backward and hurries out the door,\n\
nearly tripping in his rush. The door slams shut behind him with a sharp echo.\n" << std::endl;
	std::cout << "The Bureaucrat leans back into his chair, sighing heavily as he picks up the\n\
next stack of papers. The chaos outside fades, and he sinks back into the familiar rhythm\n\
of bureaucracy, the endless drone of paperwork calling him home.\n" << std::endl;
	std::cout << "\n------------THE END------------\n" << std::endl;
}


void test(Bureaucrat& sir, Intern& intern, const std::string& formName, const std::string& target) {

	AForm *form;

	form = intern.makeForm(formName, target);
	std::cout << "\n" << sir.getName() << " the bureaucrat attempts to sign and execute the form...\n" << std::endl;
	sir.signForm(*form);
	sir.executeForm(*form);
	delete form;
}


int main(void) {
	Bureaucrat ruben("Ruben", 25);
	Intern		randomIntern;

	intro(ruben);
	std::cout << "\n\t< ROUND1 >\n" << std::endl;
	std::cout << ruben.getName() << ": The first one is a Shrubbery Creation Form to plant trees in the Garden.\n";
	try {
		test(ruben, randomIntern, "SC", "Garden");
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n\t< ROUND2 >\n" << std::endl;
	std::cout << ruben.getName() << ": The 2nd one is a Robotomy Request Form to robotomize my housemaid.\n";
	try {
		test(ruben, randomIntern, "RR", "Housemaid");
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n\t< ROUND3 >\n" << std::endl;
	std::cout << ruben.getName() << ": The 3rd form is a Presidential Pardon Form to apologize to God.\n";
	try {
		test(ruben, randomIntern, "PP", "God");
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
		std::cout << "\n\t< ROUND4 >\n" << std::endl;
	std::cout << ruben.getName() << ": Well it's hard to apologize for the sins properly. So lets try again.\n";
	for (int i = 0; i < 20; i++)
		ruben.incrementGrade();
	std::cout << ruben.getName() << " increased his grade by praying.\n*Cheerful Level-up Sound*\n" << std::endl;
	try {
		test(ruben, randomIntern, "PP", "God");
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
		std::cout << "\n\t< ROUND5 >\n" << std::endl;
	std::cout << ruben.getName() << ": Ok, and the last form is a IncreaseSaleryForm to give you a raise.\n";
	try {
		test(ruben, randomIntern, "IS", "Raise");
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << ruben.getName() << ": I fooled ya, there is no raise for ya! Now get outta here!\n" << std::endl;
	ending();
	return 0;
}
