
#include "Animal.hpp"
#include "PrintColor.hpp"

Animal::Animal () {
	printConstructor("Animal");
}

Animal::~Animal () {
	printDestructor("Animal");
}

Animal::Animal ( const Animal &Animal )
: _type(Animal._type) {
	printCopyConstructor("Animal");
}

Animal& Animal::operator= ( const Animal& Animal ) {
	printCopyAssignmentOperator("Animal");
	if (this != &Animal) {
		this->_type = Animal._type;
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
