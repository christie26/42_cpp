
#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

// void leak() {
// 	system("leaks zombie");
// }

int main() {

// declare directly and annoouce
{
	Zombie gam = Zombie("gam");
	gam.announce();
}

// use randomChump
	randomChump("gon");

// use newZombie
	Zombie *lee = newZombie("lee");
	delete lee;

// anonymous zombie
	Zombie gun = Zombie();
	gun.announce();

	// atexit (&leak);
}
