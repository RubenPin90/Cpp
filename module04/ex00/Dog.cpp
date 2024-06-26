
#include "Dog.hpp"

Dog::Dog(const std::string& type) : Animal(type) {
	std::cout << GREEN "[Dog Constructor]:\t" RESET;
	std::cout << "An Dog of type " << m_type << " born." << std::endl;
}

Dog::Dog(const Dog& ref) : Animal(ref.getType()) {
	std::cout << BLUE "[Dog Copy Constructor]:\t" RESET;
	std::cout << "An Dog clone of type " << m_type << " born." << std::endl;
}

Dog::~Dog() {
	std::cout << RED "[Dog Deconstructor]:\t" RESET;
	std::cout << "Dog " << m_type << " has been destroyed." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) { 
	std::cout << BLUE "[Dog Assignement]:\t" RESET;
	std::cout << "Dog Assignement Operator called." << std::endl;
	m_type = rhs.m_type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << YELLOW "[Action//makeSound]\t" RESET;
	std::cout << "WooooooffffWooooffff." << std::endl;
}
