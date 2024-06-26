#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include <iostream>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class WrongCat : public WrongAnimal {
	public:
	//Constructors
		WrongCat(const std::string& type = "WrongCat");
		WrongCat(const WrongCat& ref);

	//Deconstructor
		~WrongCat();

	//Operator Overload Functions
		WrongCat& operator=(const WrongCat& rhs);

	//Public Methods
		void makeSound() const;
	
	//Getter
		std::string getType() const;

};

#endif
