
#include "WrongDog.hpp"
#include "PrintColor.hpp"

WrongDog::WrongDog () {
	printConstructor("WrongDog");
	setType("WrongDog");
}

WrongDog::~WrongDog () {
	printDestructor("WrongDog");
}

WrongDog::WrongDog ( const WrongDog &wrongDog ) {
	printCopyConstructor("WrongDog");
	this->_type = wrongDog._type;
}

WrongDog& WrongDog::operator= ( const WrongDog& wrongDog ) {
	printCopyAssignmentOperator("WrongDog");
	if (this != &wrongDog) {
		this->_type = wrongDog._type;
	}
	return *this;
}

void WrongDog::makeSound( void ) const {
	std::cout << "WrongDog: bark ! bark !" << std::endl;
}