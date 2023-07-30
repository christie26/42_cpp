
#include "HumanB.hpp"
#include <iostream>


HumanB::HumanB(std::string name) : _name(name) {
	std::cout << "HumanB, " << name << " is created" << std::endl;
	_weapon = NULL;
}

void HumanB::attack () {
	if (getWeapon().empty())
		std::cout << getName() << " doesn't have a weapon" << std::endl;
	else
		std::cout << getName() << " attacks with their " << getWeapon() << std::endl;
}

const std::string &HumanB::getName() {
	
	std::string &name = _name;

	return (name);
}

std::string HumanB::getWeapon() {
	if (!(_weapon))
		return ("");
	return _weapon->getType();
}

void HumanB::setWeapon(Weapon &weapon) {
	
	this->_weapon = &weapon;
}
// get reference -> change it to pointer 
