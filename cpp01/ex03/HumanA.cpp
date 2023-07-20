
#include "HumanA.hpp"
#include <iostream>


HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
	// _weapon = weapon;
	std::cout << "HumanA, " << name << " is created" << std::endl;
}

void HumanA::attack () {
	std::cout << getName() << " attacks with their " << getWeapon() << std::endl;
}

const std::string &HumanA::getName() {
	
	std::string &name = _name;

	return (name);
}

std::string HumanA::getWeapon() {
	
	return _weapon.getType();
}
