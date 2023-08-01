
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {

protected:
	std::string _type;

public:

	WrongAnimal( void );
	virtual ~WrongAnimal( void );
	WrongAnimal (WrongAnimal &wrongAnimal);
	WrongAnimal& operator= (const WrongAnimal& wrongAnimal);

	const std::string getType () const;
	
	void setType(std::string type);

	void makeSound( void ) const;
};

#endif
