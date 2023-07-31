
#include "FragTrap.hpp"

FragTrap::FragTrap ( std::string name )
: ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << Blue << "Frag, Default constructor called" << Reset << std::endl;
}

FragTrap::~FragTrap () {
	std::cout << Red << "Frag, Destructor called" << Reset <<std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "Do you want to do high five with me ?" << std::endl;
}

void FragTrap::attack(const std::string& target) {

	if (_hitPoints <= 0) {
		std::cout << _name << " doesn't have any hit points" << std::endl;
	} else if (_energyPoints <= 0) {
		std::cout << _name << " doesn't have any energy points" << std::endl;
	} else {
		_energyPoints--;
		std::cout	<< "FragTrap " << Cyan << _name << Reset
					<< " attacks " << Cyan << target << Reset
					<< " causing " << Cyan << _attackDamage << Reset
					<< " points of damage!" 
					<< std::endl;
	}
}