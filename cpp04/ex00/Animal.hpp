
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {

protected:
	std::string _type;

public:

	Animal( void );
	virtual ~Animal( void );
	Animal (Animal &animal);
	Animal& operator= (const Animal& animal);

	const std::string getType () const;
	
	void setType(std::string type);

	virtual void makeSound( void ) const;
};

#endif
