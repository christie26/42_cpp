
#include "Cat.hpp"
#include "PrintColor.hpp"

Cat::Cat () {
	printConstructor("Cat");
	setType("Cat");
}

Cat::~Cat () {
	printDestructor("Cat");
}

Cat::Cat ( const Cat &cat ) {
	printCopyConstructor("Cat");
	this->_type = cat._type;
}

Cat& Cat::operator= ( const Cat& cat ) {
	printCopyAssignmentOperator("Cat");
	if (this != &cat) {
		this->_type = cat._type;
	}
	return *this;
}

void Cat::makeSound( void ) const {
	std::cout << "Cat: meow ! meow !" << std::endl;
}
