#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( std::string name )
: _name(name) ,_hitPoints( 10 ), _energyPoints( 10 ), _attackDamage ( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {

}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRepaired(unsigned int amount) {

}
