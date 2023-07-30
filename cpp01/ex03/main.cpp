
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
		Weapon club = Weapon("Lightsaber");
		HumanA alice("Alice", club);
		alice.attack();
		club.setType("Sniper");
		alice.attack();
	}
	std::cout << std::endl;
	{
		Weapon club = Weapon("Lightsaber");
		HumanB bob("Bob");
		bob.attack();
		bob.setWeapon(club);
		bob.attack();
		club.setType("Sniper");
		bob.attack();
	}
	return 0;
}
