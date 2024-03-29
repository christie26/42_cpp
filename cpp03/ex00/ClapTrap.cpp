
#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( std::string name )
: _name(name) ,_hitPoints( 10 ), _energyPoints( 10 ), _attackDamage ( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap () {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap ( const ClapTrap &clapTrap )
: _name(clapTrap._name), _hitPoints(clapTrap._hitPoints), 
_energyPoints(clapTrap._energyPoints), _attackDamage(clapTrap._attackDamage) {
	std::cout << "Copy constructor called" << std::endl; 
	}

ClapTrap& ClapTrap::operator= ( const ClapTrap& clapTrap ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &clapTrap) {
		this->_name = clapTrap._name;
		this->_hitPoints = clapTrap._hitPoints; 
		this->_energyPoints = clapTrap._energyPoints; 
		this->_attackDamage = clapTrap._attackDamage; 
	}
	return *this;
}

bool ClapTrap::stillAlive() {
	if (_hitPoints <= 0) {
		std::cout << _name << " doesn't have "
				<< Red << "any hit points" << Reset << std::endl;
		return false;
	} else if (_energyPoints <= 0) {
		std::cout << _name << " doesn't have "
				<< Red << "any energy points" << Reset << std::endl;
		return false;
	}
	return true;
}

void ClapTrap::printStatus() {
	std::cout	<< Green << _name << Reset
				<< " has " << Green << _hitPoints << Reset
				<< " hit points, and " 
				<< Green << _energyPoints << Reset
				<< " energy points!" 
				<< std::endl;
}

void ClapTrap::setAttackDamage( unsigned int amount ) {
	_attackDamage = amount;
}

void ClapTrap::attack( const std::string& target ) {

	if (!stillAlive())
		return ;
	_energyPoints--;
	std::cout	<< "ClapTrap " << Green << _name << Reset
				<< " attacks " << Green << target << Reset
				<< " causing " << Green << _attackDamage << Reset
				<< " points of damage!" 
				<< std::endl;
	printStatus();
}

void ClapTrap::takeDamage( unsigned int amount ) {
	
	if (!stillAlive())
		return ;
	_hitPoints -= amount;
	std::cout	<< "ClapTrap " << Green << _name << Reset
				<< " takes damage " << Green << amount << Reset
				<< " points!" 
				<< std::endl;
	printStatus();
}

void ClapTrap::beRepaired( unsigned int amount ) {

	if (!stillAlive())
		return ;
	_energyPoints--;
	_hitPoints += amount;
	std::cout	<< "ClapTrap " << Green << _name << Reset
				<< " repair oneself " << Green << amount << Reset
				<< " hit point!" 
				<< std::endl;
	printStatus();
}
