
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:

	WrongCat( void );
	~WrongCat( void );
	WrongCat (WrongCat &wrongCat);
	WrongCat& operator= (const WrongCat& wrongCat);

	void makeSound( void ) const;

};

#endif 
