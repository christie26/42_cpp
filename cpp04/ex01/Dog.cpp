
#include "Dog.hpp"
#include "PrintColor.hpp"

Dog::Dog () {
	printConstructor("Dog");
	setType("Dog");
	_dogBrain = new Brain;
}

Dog::~Dog () {
	printDestructor("Dog");
	delete(_dogBrain);
}

Dog::Dog (Dog &dog) {
	printCopyConstructor("Dog");
	this->_type = dog._type;
	_dogBrain = new Brain(*dog._dogBrain);
}

Dog& Dog::operator= (const Dog& dog) {
	printCopyAssignmentOperator("Dog");
	if (this != &dog) {
		this->_type = dog._type;
		_dogBrain = new Brain(*dog._dogBrain);
	}
	return *this;
}

void Dog::makeSound( void ) const {
	std::cout << "Dog: bark ! bark !" << std::endl;
}

Brain* Dog::getBrain( void ) {
	return (_dogBrain);
}

void Dog::setBrain( Brain* brain) {
	_dogBrain = brain;
}