#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal {
	public:
	//Constructors
		Animal();
		Animal(const Animal& ref);

	//Deconstructor
		virtual ~Animal();

	//Operator Overload Functions
		Animal& operator=(const Animal& rhs);

	//Public Methods
		virtual void makeSound();
	
	protected:
		std::string m_type;

};

#endif