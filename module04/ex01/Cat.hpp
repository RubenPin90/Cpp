#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
	public:
	//Constructors
		Cat(const std::string& type = "Cat");
		Cat(const Cat& ref);

	//Deconstructor
		~Cat();

	//Operator Overload Functions
		Cat& operator=(const Cat& rhs);

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