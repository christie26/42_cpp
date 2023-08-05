#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {

	FragTrap F("Frog");
	F.attack("you");
	F.highFivesGuys();
	F.takeDamage(50);
	F.takeDamage(30);
	// change two line below to test
	F.beRepaired(100);
	F.takeDamage(30);
}
