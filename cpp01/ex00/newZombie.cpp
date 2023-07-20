
#include "Zombie.hpp"

// 1. allocate with new 
// 2. give them a name

Zombie* newZombie( std::string name ) {
	Zombie *newOne = new Zombie(name);
	return (newOne);
}