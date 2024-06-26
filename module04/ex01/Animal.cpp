
#include "Animal.hpp"

Animal::Animal(const std::string& type) : m_type(type) {
	std::cout << GREEN "[Animal Constructor]:\t" RESET;
	std::cout << "An Animal of type " << m_type << " born." << std::endl;
}

Animal::Animal(const Animal& ref) : m_type(ref.getType()) {
	std::cout << BLUE "[Animal Copy Constructor]:\t" RESET;
	std::cout << "An Animal clone of type " << m_type << " born." << std::endl;
}

Animal::~Animal() {
	std::cout << RED "[Animal Deconstructor]:\t" RESET;
	std::cout << "Animal " << m_type << " has been destroyed." << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) { 
	std::cout << BLUE "[Animal Assignement]:\t" RESET;
	std::cout << "Animal Assignement Operator called." << std::endl;
	m_type = rhs.m_type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << YELLOW "[Action//makeSound]\t" RESET;
	std::cout << "Animal makes undefined Sound." << std::endl;
}

std::string Animal::getType() const {
	return m_type;
}
