
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main( void ) {
	{
		Animal a;

		Animal b = a;
		Animal c;
		c = a;
	}
	std::cout << "--------------------" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* cat = new Cat();
		const Animal* dog = new Dog();
		std::cout << cat->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		cat->makeSound(); //will output the cat sound!
		dog->makeSound();
		meta->makeSound();

		delete(meta);
		delete(cat);
		delete(dog);
	}
	std::cout << "--------------------" << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();
		const WrongAnimal* dog = new WrongDog();
		std::cout << cat->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		cat->makeSound(); //will output the cat sound!
		dog->makeSound();
		meta->makeSound();

		delete(meta);
		delete(cat);
		delete(dog);
	}
	return 0;

}