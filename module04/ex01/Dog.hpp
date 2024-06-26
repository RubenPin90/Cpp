#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
	public:
	//Constructors
		Dog(const std::string& type = "Dog");
		Dog(const Dog& ref);

	//Deconstructor
		~Dog();

	//Operator Overload Functions
		Dog& operator=(const Dog& rhs);

	//Public Methods
		void makeSound() const;
	
	//Getter
		std::string getIdeas(int i) const;

	//Setter
		void setIdeas(std::string idea, int id);

	private:
		Brain* m_mind;

};

#endif
