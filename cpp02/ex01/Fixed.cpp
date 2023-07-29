
#include "Fixed.hpp"

Fixed::Fixed () 
: rawValue ( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( const int intValue ) 
: rawValue ( intValue << 8 ) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed ( const float floatValue )
: rawValue( floatValue * ( 1 << 8 ) )  {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed (const Fixed &fixed) 
: rawValue(fixed.rawValue) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed ( ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->rawValue = fixed.rawValue; 
	}
	return *this;
}

std::ostream& operator<< (std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

int Fixed::getRawBits( void ) const {
	return ( this->rawValue );
}

void Fixed::setRawBits( int const raw ) {
	this->rawValue = raw;
	return ;
}

float Fixed::toFloat() const {
    return (static_cast<float>(this->rawValue) / (1 << this->fractionalBits));
}

int Fixed::toInt() const {
    return (static_cast<int>(this->rawValue) / (1 << this->fractionalBits));
}