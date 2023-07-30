#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( std::string name )
: _name(name) ,_hitPoints( 10 ), _energyPoints( 10 ), _attackDamage ( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap () {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap (ClapTrap &clapTrap) 
: _name(clapTrap._name) {
	std::cout << "Copy constructor called" << std::endl; 
	}

ClapTrap& ClapTrap::operator= (const ClapTrap& clapTrap) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &clapTrap) {
		this->_name = clapTrap._name; 
	}
	return *this;
}

void ClapTrap::setAttackDamage(int amount) {
	_attackDamage = amount;
}
void ClapTrap::attack(const std::string& target) {

	if (_hitPoints == 0) {
		std::cout << _name << " doesn't have no hit points" << std::endl;
	} else if (_energyPoints == 0) {
		std::cout << _name << " doesn't have no energy points" << std::endl;
	} else {
		_energyPoints--;
		std::cout	<< "ClapTrap " << Green << _name << Reset
					<< " attacks " << Green << target << Reset
					<< " causing " << Green << _attackDamage << Reset
					<< " points of damage!" 
					<< std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	
	if (_hitPoints == 0) {
		std::cout << _name << " doesn't have no hit points" << std::endl;
	} else if (_energyPoints == 0) {
		std::cout << _name << " doesn't have no energy points" << std::endl;
	} else {
		_energyPoints--;
		_hitPoints -= amount;
		std::cout	<< "ClapTrap " << Green << _name << Reset
					<< " takes damage " << Green << amount << Reset
					<< " points!" 
					<< std::endl;
		std::cout	<< "ClapTrap " << Green << _name << Reset
					<< " now has " << Green << _hitPoints << Reset
					<< " points!" 
					<< std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (_hitPoints == 0) {
		std::cout << _name << " doesn't have no hit points" << std::endl;
	} else if (_energyPoints == 0) {
		std::cout << _name << " doesn't have no energy points" << std::endl;
	} else {
		_energyPoints--;
		_hitPoints += amount;
		std::cout	<< "ClapTrap " << Green << _name << Reset
					<< " repair oneself " << Green << amount << Reset
					<< " hit point!" 
					<< std::endl;
		std::cout	<< "ClapTrap " << Green << _name << Reset
					<< " now has " << Green << _hitPoints << Reset
					<< " points!" 
					<< std::endl;
	}
}
