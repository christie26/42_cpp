
#include "ScavTrap.hpp"

ScavTrap::ScavTrap ( std::string name )
: ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << Blue << "Scav, Default constructor called" << Reset << std::endl;
}

ScavTrap::~ScavTrap () {
	std::cout << Red << "Scav, Destructor called" << Reset <<std::endl;
}

void ScavTrap::attack( const std::string& target ) {
	if (!stillAlive())
		return ;
	_energyPoints--;
	std::cout	<< "ScavTrap " << Yellow << _name << Reset
				<< " attacks " << Yellow << target << Reset
				<< " causing " << Yellow << _attackDamage << Reset
				<< " points of damage!" 
				<< std::endl;
	printStatus();
}

void ScavTrap::guardGate() {
	std::cout	<< "ScavTrap " << Yellow << _name << Reset
				 << " is now in Gate keeper mode." << std::endl;
}
