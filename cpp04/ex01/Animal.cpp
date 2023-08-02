
#include "Animal.hpp"
#include "PrintColor.hpp"

Animal::Animal () {
	printConstructor("Animal");
}

Animal::~Animal () {
	printDestructor("Animal");
}

Animal::Animal (const Animal &animal) 
: _type(animal._type) {
	printCopyConstructor("Animal");
}

Animal& Animal::operator= (const Animal& animal) {
	printCopyAssignmentOperator("Animal");
	if (this != &animal)
		this->_type = animal._type;

	return *this;
}

const std::string Animal::getType() const {
	return this->_type;
}

void Animal::setType(std::string type) {
	this->_type = type;
}

void Animal::makeSound( void ) const {
	std::cout << "Animal is making sound" << std::endl;
}

Brain* Animal::getBrain( void ) {
	return 0;
}
