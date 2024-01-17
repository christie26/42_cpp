
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {

	{
		// stack
		ScavTrap C("Chistie");
		ScavTrap D("Daniel");
		C.guardGate();
		C.attack("Daniel");
		D.takeDamage(20);
		D.takeDamage(20);
		// change the order to kill Daniel ! 
		D.beRepaired(30);
		D.takeDamage(70);
	}
	std::cout << std::endl;
	{
		// heap
		ScavTrap* happy = new ScavTrap("happy");
		happy->attack("sad");
		delete happy;

	}
}
