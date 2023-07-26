
#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed () {
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed () {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;

	this->setRawBits(fixed.getRawBits());
}

Fixed& Fixed::operator= (const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;

	this->setRawBits(fixed.getRawBits());
    return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return ( this->value );
}

void Fixed::setRawBits( int const raw ) {
	this->value = raw << this->fractionalBits;
	return ;
}