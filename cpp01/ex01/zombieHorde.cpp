
#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name ) {
	
	Zombie* zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++) {
    	zombieHorde[i] = Zombie(name);
	}

	return (zombieHorde);		

}

// cannot initialize at the same time with allocate array
// you can use C++11 to initialize the dynamically allocated array using an initializer list: