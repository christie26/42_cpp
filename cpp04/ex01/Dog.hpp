
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

private:
	Brain* _dogBrain;

public:

	Dog( void );
	~Dog( void );
	Dog (Dog &dog);
	Dog& operator= (const Dog& dog);

	void makeSound( void ) const;

	Brain* getBrain( void );
	void setBrain( Brain* brain );
};

#endif 
