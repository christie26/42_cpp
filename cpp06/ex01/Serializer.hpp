
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include "Data.hpp"


class Serializer {

private:
	Serializer ( void );
	~Serializer( void );
	Serializer ( const Serializer& );
	Serializer& operator= ( const Serializer& );

public:
	static uintptr_t serialize( Data* ptr );
	static Data* deserialize( uintptr_t raw );

};


#endif
