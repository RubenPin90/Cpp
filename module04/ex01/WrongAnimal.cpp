
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string& type) : m_type(type) {
	std::cout << GREEN "[WrongAnimal Constructor]:\t" RESET;
	std::cout << "An WrongAnimal of type " << m_type << " born." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref) : m_type(ref.getType()) {
	std::cout << BLUE "[WrongAnimal Copy Constructor]:\t" RESET;
	std::cout << "An WrongAnimal clone of type " << m_type << " born." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED "[WrongAnimal Deconstructor]:\t" RESET;
	std::cout << "WrongAnimal " << m_type << " has been destroyed." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) { 
	std::cout << BLUE "[WrongAnimal Assignement]:\t" RESET;
	std::cout << "WrongAnimal Assignement Operator called." << std::endl;
	m_type = rhs.m_type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << YELLOW "[Action//makeSound]\t" RESET;
	std::cout << "WrongAnimal makes undefined Sound." << std::endl;
}

std::string WrongAnimal::getType() const {
	return m_type;
}
