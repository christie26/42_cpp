
#include "Animal.hpp"
#include "PrintColor.hpp"

Animal::Animal () {
	printConstructor("Animal");
	_brain = new Brain;
}

Animal::~Animal () {
	printDestructor("Animal");
}

Animal::Animal (Animal &animal) 
: _type(animal._type) {
	printCopyConstructor("Animal");
	_brain = new Brain(*animal._brain);
}

Animal& Animal::operator= (const Animal& animal) {
	printCopyAssignmentOperator("Animal");
	if (this != &animal) {
		this->_type = animal._type;
		_brain = new Brain(*animal._brain);
	}
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
	// return (_brain);
}

void Animal::setBrain( Brain* brain) {
	_brain = brain;
}