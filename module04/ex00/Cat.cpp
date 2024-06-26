
#include "Cat.hpp"

Cat::Cat(const std::string& type) : Animal(type) {
	std::cout << GREEN "[Cat Constructor]:\t" RESET;
	std::cout << "An Cat of type " << m_type << " born." << std::endl;
}

Cat::Cat(const Cat& ref) : Animal(ref.getType()) {
	std::cout << BLUE "[Cat Copy Constructor]:\t" RESET;
	std::cout << "An Cat clone of type " << m_type << " born." << std::endl;
}

Cat::~Cat() {
	std::cout << RED "[Cat Deconstructor]:\t" RESET;
	std::cout << "Cat " << m_type << " has been destroyed." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) { 
	std::cout << BLUE "[Cat Assignement]:\t" RESET;
	std::cout << "Cat Assignement Operator called." << std::endl;
	m_type = rhs.m_type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << YELLOW "[Action//makeSound]\t" RESET;
	std::cout << "Meeeeeeeeeowwwww." << std::endl;
}
