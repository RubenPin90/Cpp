
#include "Cat.hpp"

Cat::Cat(const std::string& type) : Animal(type) {
	std::cout << GREEN "[Cat Constructor]:\t" RESET;
	std::cout << "A Cat of type " << m_type << " is born." << std::endl;
	m_mind = new Brain();
}

Cat::Cat(const Cat& ref) : Animal(ref.getType()) {
	std::cout << BLUE "[Cat Copy Constructor]:\t" RESET;
	std::cout << "A Cat clone of type " << m_type << " is born." << std::endl;
	*this = ref;
}

Cat::~Cat() {
	std::cout << RED "[Cat Deconstructor]:\t" RESET;
	std::cout << "Cat " << m_type << " has been destroyed." << std::endl;
	delete m_mind;
}

Cat& Cat::operator=(const Cat& rhs) { 
	std::cout << BLUE "[Cat Assignement]:\t" RESET;
	std::cout << "Cat Assignement Operator called." << std::endl;
	if (this != &rhs) {
		m_type = rhs.m_type;
		m_mind = new Brain(*rhs.m_mind);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << YELLOW "[Action//makeSound]\t" RESET;
	std::cout << "Meeeeeeeeeowwwww." << std::endl;
}

std::string Cat::getIdeas(int i) const {
	return m_mind->getIdeas(i);
}

void Cat::setIdeas(std::string idea, int id) {
	m_mind->setIdeas(idea, id);
}
