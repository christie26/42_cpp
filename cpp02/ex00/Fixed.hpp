
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

private:

	int value;
	static const int fractionalBits = 8;

public:

	Fixed();
	~Fixed();
	Fixed ( const Fixed &fixed ); // copy constructor 
	Fixed& operator= ( const Fixed& fixed ); // copy assignment operator overload

	int getRawBits( void ) const;
	void setRawBits( int const raw );

};

#endif
