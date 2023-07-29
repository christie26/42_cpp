#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "----------------" << std::endl;

	if (a > b)
		std::cout << "a is bigger than b" << std::endl;
	else
		std::cout << "a is not bigger than b" << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	Fixed& ref_a = a;
	std::cout << Fixed::max( ref_a, b ) << std::endl;
	
	std::cout << "----------------" << std::endl;

	Fixed e;
	std::cout << e << std::endl;
	std::cout << ++e << std::endl;
	std::cout << e << std::endl;
	std::cout << e++ << std::endl;
	std::cout << e << std::endl;
	std::cout << "----------------" << std::endl;
	
	Fixed f1( 5.05f );
	Fixed f2( 2 );
	Fixed const f( f1 / f2 );
	// Fixed const f( f1 * f2 );
	std::cout << "f1: " << f1 << std::endl;
	std::cout << "f2: " << f2 << std::endl;
	std::cout << "f:  "	<< f  << std::endl;
	std::cout << "----------------" << std::endl;


	return 0;
}
