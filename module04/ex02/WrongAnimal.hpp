#ifndef WORNGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class WrongAnimal {
	public:
	//Constructors
		WrongAnimal(const std::string& type = "WrongAnimal");
		WrongAnimal(const WrongAnimal& ref);

	//Deconstructor
		~WrongAnimal();

	//Operator Overload Functions
		WrongAnimal& operator=(const WrongAnimal& rhs);

	//Public Methods
		void makeSound() const;
	
	//Getter
		std::string getType() const;
	
	protected:
		std::string m_type;

};

#endif