
#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( void ) {
	std::cout << "<no name>" << " is created" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << name << " is created" << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << getName() << " is died" << std::endl;
}

void Zombie::announce( void ) {
	std::cout << getName() << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName() {
	if ( _name.empty() )
		return ( "<no name>" );
	else
		return (_name);
}

void Zombie::setName(std::string name) {
	this->_name = name;
}
