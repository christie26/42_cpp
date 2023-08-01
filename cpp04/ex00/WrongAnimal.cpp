
#include "WrongAnimal.hpp"
#include "PrintColor.hpp"

WrongAnimal::WrongAnimal () {
	printConstructor("WrongAnimal");
}

WrongAnimal::~WrongAnimal () {
	printDestructor("WrongAnimal");
}

WrongAnimal::WrongAnimal (WrongAnimal &wrongAnimal) 
: _type(wrongAnimal._type) {
	printCopyConstructor("WrongAnimal");
	}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& wrongAnimal) {
	printCopyAssignmentOperator("WrongAnimal");
	if (this != &wrongAnimal) {
		this->_type = wrongAnimal._type;
	}
	return *this;
}

const std::string WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::setType(std::string type) {
	this->_type = type;
}

void WrongAnimal::makeSound( void ) const {
	std::cout << "WrongAnimal is making sound" << std::endl;
}
