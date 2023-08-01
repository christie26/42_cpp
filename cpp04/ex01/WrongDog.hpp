
#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {

public:

	WrongDog( void );
	~WrongDog( void );
	WrongDog (WrongDog &dog);
	WrongDog& operator= (const WrongDog& dog);

	void makeSound( void ) const;

};

#endif 
