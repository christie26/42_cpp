
#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {

	Zombie *newOne = new Zombie(name);
	
	return (newOne);

}
