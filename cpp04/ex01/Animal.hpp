
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal {

protected:
	std::string _type;
	// Brain* _brain;

public:

	Animal( void );
	virtual ~Animal( void );
	Animal (const Animal &animal);
	Animal& operator= (const Animal& animal);

	const std::string getType () const;
	
	void setType(std::string type);

	virtual void makeSound( void ) const;
	virtual Brain* getBrain( void );
};

#endif
