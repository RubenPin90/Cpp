#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#define SIZE_OF_IDEAS 100

class Brain {
	public:
	//Constructors
		Brain();
		Brain(const Brain& ref);

	//Deconstructor
		~Brain();

	//Operator Overload Functions
		Brain& operator=(const Brain& rhs);

	//Getter
		std::string getIdeas(int i) const;

	//Setter
		void setIdeas(std::string idea, int id);

	private:
		std::string m_ideas[SIZE_OF_IDEAS];

};

#endif