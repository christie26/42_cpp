
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

private:
	Brain* _catBrain;

public:

	Cat( void );
	~Cat( void );
	Cat (const Cat &cat);
	Cat& operator= (const Cat& cat);

	void makeSound( void ) const;

	Brain* getBrain( void );
	void setBrain( Brain* brain );
};

#endif 
