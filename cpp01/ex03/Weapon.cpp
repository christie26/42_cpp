
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	
	std::cout << "Weapon, " << type << " is created" << std::endl;
}

const std::string& Weapon::getType() {

	return (_type);	
}

void Weapon::setType(std::string type) {

	this->_type = type;
}
