
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {

	std::cout << "HumanA, " << name << " is created" << std::endl;
}

void HumanA::attack () {
	std::cout << getName() << " attacks with their " << getWeapon() << std::endl;
}

const std::string &HumanA::getName() {
	
	return (_name);
}

std::string HumanA::getWeapon() {
	
	return _weapon.getType();
}
