
#include "Dog.hpp"

Dog::Dog(const std::string& type) : Animal(type) {
	std::cout << GREEN "[Dog Constructor]:\t" RESET;
	std::cout << "A Dog of type " << m_type << " is born." << std::endl;
	m_mind = new Brain();
}

Dog::Dog(const Dog& ref) : Animal(ref.getType()) {
	std::cout << BLUE "[Dog Copy Constructor]:\t" RESET;
	std::cout << "A Dog clone of type " << m_type << " is born." << std::endl;
}

Dog::~Dog() {
	std::cout << RED "[Dog Deconstructor]:\t" RESET;
	std::cout << "Dog " << m_type << " has been destroyed." << std::endl;
	delete m_mind;
}

Dog& Dog::operator=(const Dog& rhs) { 
	std::cout << BLUE "[Dog Assignement]:\t" RESET;
	std::cout << "Dog Assignement Operator called." << std::endl;
	if (this != &rhs) {
		m_type = rhs.m_type;
		m_mind = new Brain(*rhs.m_mind);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << YELLOW "[Action//makeSound]\t" RESET;
	std::cout << "WooooooffffWooooffff." << std::endl;
}

std::string Dog::getIdeas(int i) const {
	return m_mind->getIdeas(i);
}

void Dog::setIdeas(std::string idea, int id) {
	m_mind->setIdeas(idea, id);
}
