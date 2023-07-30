#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	ClapTrap A("Alice");
	ClapTrap E("Etinne");

	A.setAttackDamage(5);
	A.attack("Etienne");
	E.takeDamage(5);
	E.beRepaired(7);
}
