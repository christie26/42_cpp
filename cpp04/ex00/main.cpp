
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

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
		const Animal* i = new Cat();
		const Animal* j = new Dog();
		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete(meta);
		delete(i);
		delete(j);
	}
	std::cout << "--------------------" << std::endl;
	{
		
	}
	return 0;

}