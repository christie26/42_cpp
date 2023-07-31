#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {

	{
		ClapTrap A("Alice");
		ClapTrap E("Etinne");

		A.setAttackDamage(5);
		A.attack("Etienne");
		E.takeDamage(5);
		E.beRepaired(7);
	}

	std::cout << std::endl << std::endl;

	{
		ScavTrap C("Chistie");
		C.guardGate();
		C.attack("Christie2");
		ScavTrap D = C;
		D.takeDamage(20);
		D.takeDamage(20);
		D.takeDamage(20);
		D.beRepaired(30);
		
		ScavTrap happy("happy");
		ClapTrap *h = &happy;
		h->attack("sad");
	}
}
