#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base * generate(void) {
	int randNum = rand() % 3;
	switch(randNum) {
		case 0: { return new A; }
		case 1: { return new B; }
		default: { return new C; }
	}
}

void identify(Base* p) {
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	std::cout << "Identifing by Pointer:\n";
	if (a) 
		std::cout << "- Type A -" << std::endl;
	else if (b)
		std::cout << "- Type B -" << std::endl;
	else if (c)
		std::cout << "- Type C -" << std::endl;
	else
		std::cerr << "Unknown Type. Panic!\n";
}

void identify(Base& p) {
	std::cout << "Identifing by Reference:\n";
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "+ Type A +" << std::endl;
	}
	catch (const std::exception& e) {
		try {
			B b = dynamic_cast<B&>(p);
			std::cout << "+ Type B +" << std::endl;
		}
		catch (const std::exception& e) {
			try {
				C c = dynamic_cast<C&>(p);
				std::cout << "+ Type C +" << std::endl;
			}
			catch (const std::exception& e) {
				std::cerr << "Unkown Type: " << e.what() << std::endl;
			}
		}
	}
}


int main () {
	std::srand(std::time(NULL));
	for (int i = 0; i < 6; i++) {
		std::cout << "\n++++++++++ Loop " << i << " +++++++++++\n" << std::endl;
		Base* random = generate();
		identify(random);
		identify(*random);
		delete (random);
	}
	return 0;
}
