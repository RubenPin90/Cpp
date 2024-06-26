
#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor has been called." << std::endl;
}

Brain::Brain(const Brain& ref) {
	std::cout << "Brain Copy Constructor has been called." << std::endl;
	*this = ref;
}

Brain::~Brain() {
	std::cout << "Brain Destructor has been called." << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
	if (this != &rhs) {
		for (int i = 0; i < SIZE_OF_IDEAS; i++) {
			m_ideas[i] = rhs.m_ideas[i];
		}
	}
	return *this;
}

std::string Brain::getIdeas(int i) const {
	if (i < SIZE_OF_IDEAS)
		return m_ideas[i];
	else
		return ("Out of Brain capacity. No such thought in the brain");
}

void Brain::setIdeas(std::string idea, int id) {
	if (id < SIZE_OF_IDEAS)	
		m_ideas[id] = idea;
	else
		std::cout << "Out of Brain capacity. Brain is too small" << std::endl;
}
