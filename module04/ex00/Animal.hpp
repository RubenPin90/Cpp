#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Animal {
	public:
	//Constructors
		Animal(const std::string& type = "Random Animal");
		Animal(const Animal& ref);

	//Deconstructor
		virtual ~Animal();

	//Operator Overload Functions
		Animal& operator=(const Animal& rhs);

	//Public Methods
		virtual void makeSound() const;
	
	//Getter
		std::string getType() const;
	
	protected:
		std::string m_type;

};


#endif
