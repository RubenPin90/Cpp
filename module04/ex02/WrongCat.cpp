
#include "WrongCat.hpp"

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type) {
	std::cout << GREEN "[WrongCat Constructor]:\t" RESET;
	std::cout << "An WrongCat of type " << m_type << " born." << std::endl;
}

WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref.getType()) {
	std::cout << BLUE "[WrongCat Copy Constructor]:\t" RESET;
	std::cout << "An WrongCat clone of type " << m_type << " born." << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << RED "[WrongCat Deconstructor]:\t" RESET;
	std::cout << "WrongCat " << m_type << " has been destroyed." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) { 
	std::cout << BLUE "[WrongCat Assignement]:\t" RESET;
	std::cout << "WrongCat Assignement Operator called." << std::endl;
	m_type = rhs.m_type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << YELLOW "[Action//makeSound]\t" RESET;
	std::cout << "MeoooooooowwwwwwwMeowwwwwwwww." << std::endl;
}

std::string WrongCat::getType() const {
	return m_type;
}
