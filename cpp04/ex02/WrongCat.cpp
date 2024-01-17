
#include "WrongCat.hpp"
#include "PrintColor.hpp"

WrongCat::WrongCat () {
	printConstructor("WrongCat");
	setType("WrongCat");
}

WrongCat::~WrongCat () {
	printDestructor("WrongCat");
}

WrongCat::WrongCat ( const WrongCat &wrongCat ) {
	printCopyConstructor("WrongCat");
	this->_type = wrongCat._type;
}

WrongCat& WrongCat::operator= ( const WrongCat& wrongCat ) {
	printCopyAssignmentOperator("WrongCat");
	if (this != &wrongCat) {
		this->_type = wrongCat._type;
	}
	return *this;
}

void WrongCat::makeSound( void ) const {
	std::cout << "WrongCat: meow ! meow !" << std::endl;
}