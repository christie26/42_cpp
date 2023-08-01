
#include "Dog.hpp"
#include "PrintColor.hpp"

Dog::Dog () {
	printConstructor("Dog");
	setType("Dog");
}

Dog::~Dog () {
	printDestructor("Dog");
}

Dog::Dog (Dog &dog) {
	printCopyConstructor("Dog");
	this->_type = dog._type;
}

Dog& Dog::operator= (const Dog& dog) {
	printCopyAssignmentOperator("Dog");
	if (this != &dog) {
		this->_type = dog._type;
	}
	return *this;
}

void Dog::makeSound( void ) const {
	std::cout << "Dog: bark ! bark !" << std::endl;
}