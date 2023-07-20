
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	Weapon test = Weapon("type 1");
	std::cout << "weapon type: " << test.getType() << std::endl;
	test.setType("type 2");
	std::cout << "weapon type: " << test.getType() << std::endl << std::endl;

	{
		Weapon club = Weapon("crude spiked club");
		HumanA alice("Alice", club);
		alice.attack();
		club.setType("some other type of club");
		alice.attack();
	}
	std::cout << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB bob("Bob");
		bob.attack();
		bob.setWeapon(club);
		club.setType("some other type of club");
		bob.attack();
	}
	return 0;
}