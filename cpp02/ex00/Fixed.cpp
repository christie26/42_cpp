
#include "Fixed.hpp"

Fixed::Fixed () 
: value ( 0 ) {
	std::cout << "Default constructor called" << std::endl; 
	}

Fixed::~Fixed () {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed ( const Fixed &fixed ) 
: value (fixed.value) {
	std::cout << "Copy constructor called" << std::endl; 
	}

Fixed& Fixed::operator= ( const Fixed& fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->value = fixed.value; 
	}
	return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return ( this->value );
}

void Fixed::setRawBits( int const raw ) {
	this->value = raw;
	return ;
}
