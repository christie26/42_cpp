
#include "Cat.hpp"
#include "PrintColor.hpp"

Cat::Cat () {
	printConstructor("Cat");
	setType("Cat");
	Brain* catBrain = new Brain;
	_catBrain = catBrain;
}

Cat::~Cat () {
	printDestructor("Cat");
	delete(_catBrain);
}

Cat::Cat (const Cat &cat) {
	printCopyConstructor("Cat");
	this->_type = cat._type;
	_catBrain = new Brain(*cat._catBrain);
}

Cat& Cat::operator= (const Cat& cat) {
	printCopyAssignmentOperator("Cat");
	if (this != &cat) {
		this->_type = cat._type;
		_catBrain = new Brain(*cat._catBrain);
	}
	return *this;
}

void Cat::makeSound( void ) const {
	std::cout << "Cat: meow ! meow !" << std::endl;
}

Brain* Cat::getBrain( void ) {
	return (_catBrain);
}

void Cat::setBrain( Brain* brain) {
	*_catBrain = *brain;
}