
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

void leak() {
	system("leaks zombie");
}

int main() {

// one zombie
{
	Zombie gam = Zombie("gam");
	gam.announce();
}

// zombieHorde
	int N = 3;
	Zombie *horde = zombieHorde(N, "happy");

	for (int i = 0; i < N; i++) {
    	horde[i].announce();
	}

	delete[] horde;

	atexit (&leak);
}
