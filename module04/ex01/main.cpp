#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#define AMOUNT 10

void ft_exit(Animal* pack[], int i) {
	for (int j = 0; j < i; j++) {
		delete pack[j];
	}
}

int main()
{
	Animal* Animalpack[AMOUNT];
	int i = 0;
	try {
		for (i = 0; i < AMOUNT; i++) {
			if (i < AMOUNT / 2) {
				Animalpack[i] = new Dog();
			} else {
				Animalpack[i] = new Cat();
			}
		}
	} catch (const std::bad_alloc& e) {
		std::cerr << "Memory Alloc Error " << e.what() << std::endl;
		return (ft_exit(Animalpack, i), FAIL);
	}
	std::cout << YELLOW "\n===================================\n" << std::endl;

	std::cout << "Test 1 / Correct Animals\n" RESET << std::endl;

	for (int j = 0; j < AMOUNT; j++) {
		std::cout << j << " I am a " << Animalpack[j]->getType() << ": ";
		Animalpack[j]->makeSound();
	}
	std::cout << YELLOW "\n===================================\n" << std::endl;

	std::cout << "Test 2 / Deep Copy\n" RESET << std::endl;

	Dog* doggy1 = dynamic_cast<Dog*>(Animalpack[1]);
	Dog* doggy2 = dynamic_cast<Dog*>(Animalpack[2]);
	Cat* kitty1 = dynamic_cast<Cat*>(Animalpack[5]);

	doggy1->setIdeas("I want to pee.", 2);
	doggy2->setIdeas("Where is my Owner to play with me?!", 101);
	kitty1->setIdeas("I want some love!", 5);
	Cat grumpycat(*kitty1);
	grumpycat.setIdeas("I hate people! Leave me alone!", 5);
	Dog stupiddog(*doggy1);
	stupiddog.setIdeas("I want to eat my shit", 2);
	std::cout << "Doggy1 Idea 2: " << doggy1->getIdeas(2) << std::endl;
	std::cout << "Doggy2 Idea 101: " << doggy1->getIdeas(101) << std::endl;
	std::cout << "Kitty1 Idea 5: " << kitty1->getIdeas(5) << std::endl;
	std::cout << "GrumpyKitten Idea 5: " << grumpycat.getIdeas(5) << std::endl;
	std::cout << "StupidDog Idea 2: " << stupiddog.getIdeas(5) << std::endl;
	ft_exit(Animalpack, AMOUNT);
	std::cout << YELLOW "\n===================================\n" << std::endl;

	std::cout << "Test 3 / Deep Copy2\n" RESET << std::endl;
	Dog basic("doggy");
	Cat basic2("kitty");
	basic.makeSound();
	basic2.makeSound();
	{
		Cat tmp1 = basic2;
		Dog tmp = basic;
	}
	basic.makeSound();
	basic2.makeSound();
	return (SUCCESS);
}
