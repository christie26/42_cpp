
#include "Zombie.hpp"

void leak() {
	system("leaks zombie");
}

int main() {

	{
		Zombie gam = Zombie("gam");
		gam.announce();
	}
	std::cout << std::endl;

	randomChump("gon");
	
	std::cout << std::endl;
	
	Zombie* lee;
	{
		lee = newZombie("lee");
	}
	std::cout << std::endl;
	
	Zombie gun = Zombie();
	lee->announce();
	gun.announce();
	delete lee;

	// atexit (&leak);
}
