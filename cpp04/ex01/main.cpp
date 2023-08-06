
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

void leak(void) {
	system("leaks a.out");
}

int main( void ) {

	Brain smartBrain;
	smartBrain.setIdea(42, "I am smart");
	Brain stupidBrain;
	stupidBrain.setIdea(42, "I am stupid");
	
	std::cout << std::endl;

	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog();
	Dog* dog3 = new Dog();
	Cat* cat1 = new Cat();
	Cat* cat2 = new Cat();
	Cat* cat3 = new Cat();
	
	std::cout << std::endl;
	dog1->setBrain(&smartBrain);
	std::cout << std::endl;
	
	Animal *animalHorde[6];
	
	animalHorde[0] = new Dog(*dog1);
	animalHorde[1] = new Dog(*dog2);
	animalHorde[2] = new Dog(*dog3);
	animalHorde[3] = new Cat(*cat1);
	animalHorde[4] = new Cat(*cat2);
	animalHorde[5] = new Cat(*cat3);

// We can check deep copy with this code ! 
	dog1->setType("hihi");
	std::cout << "dog1 type(origin): " << dog1->getType() << std::endl;
	std::cout << "dog1 type(group) : " << animalHorde[0]->getType() << std::endl;

	std::cout << std::endl;

	std::cout << "dog1's brain (origin): " << dog1->getBrain()->getIdea(42) << std::endl;
	std::cout << "dog1's brain (group) : " << animalHorde[0]->getBrain()->getIdea(42) << std::endl;
	dog1->setBrain(&stupidBrain);
	std::cout << "dog1's brain (origin): " << dog1->getBrain()->getIdea(42) << std::endl;
	std::cout << "dog1's brain (group) : " << animalHorde[0]->getBrain()->getIdea(42) << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		animalHorde[i]->makeSound();

	delete dog1;
	delete dog2;
	delete dog3;
	delete cat1;
	delete cat2;
	delete cat3;

	for (int i = 0; i < 6; i++)
		delete animalHorde[i];

	// atexit(&leak);
	return 0;

}
