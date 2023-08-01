
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

public:

	Dog( void );
	~Dog( void );
	Dog (Dog &dog);
	Dog& operator= (const Dog& dog);

	void makeSound( void ) const;

};

#endif 
