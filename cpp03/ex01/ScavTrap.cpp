
#include "ScavTrap.hpp"

ScavTrap::ScavTrap ( std::string name )
: ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	guard = false;
	std::cout << Blue << "Scav, Default constructor called" << Reset << std::endl;
}

ScavTrap::~ScavTrap () {
	std::cout << Red << "Scav, Destructor called" << Reset <<std::endl;
}

void ScavTrap::attack(const std::string& target) {

	if (_hitPoints == 0) {
		std::cout << _name << " doesn't have no hit points" << std::endl;
	} else if (_energyPoints == 0) {
		std::cout << _name << " doesn't have no energy points" << std::endl;
	} else {
		_energyPoints--;
		std::cout	<< "ScavTrap " << Yellow << _name << Reset
					<< " attacks " << Yellow << target << Reset
					<< " causing " << Yellow << _attackDamage << Reset
					<< " points of damage!" 
					<< std::endl;
	}
}

void ScavTrap::guardGate() {
	guard = true;
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}