
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main( void ) {

	Animal *animalHorde[6];
	// animalHorde = new Animal [6];

	std::cout << std::endl;

	Brain smartBrain;
	smartBrain.setIdea(42, "I am smart");
	Brain stupidBrain;
	stupidBrain.setIdea(42, "I am stupid");

	// Dog* dog1 = new Dog();
	Dog* dog2 = new Dog();
	Dog* dog3 = new Dog();
	animalHorde[1] = dog2;
	animalHorde[2] = dog3;

	std::cout << std::endl;

	// Deep copy dog1 into a new memory location
	Dog dog1;
	animalHorde[0] = new Dog(dog1);
	dog1.setBrain(&smartBrain);
	std::cout << "dog1's brain: " << dog1.getBrain()->getIdea(42) << std::endl;
	std::cout << "dog1's brain from Horde: " << animalHorde[0]->getBrain()->getIdea(42) << std::endl;
	
	dog1.setBrain(&stupidBrain);
	std::cout << "dog1's brain: " << dog1.getBrain()->getIdea(42) << std::endl;
	std::cout << "dog1's brain from Horde: " << animalHorde[0]->getBrain()->getIdea(42) << std::endl;

	std::cout << std::endl;

	Cat* cat1 = new Cat();
	Cat* cat2 = new Cat();
	Cat* cat3 = new Cat();
	animalHorde[3] = cat1;
	animalHorde[4] = cat2;
	animalHorde[5] = cat3;

	std::cout << std::endl;

// You must delete directly dogs and cats as Animals.
	// delete[] animalHorde;

	return 0;

}