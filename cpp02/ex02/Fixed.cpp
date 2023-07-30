
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
: rawValue( roundf(floatValue * ( 1 << 8 )) )  {
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

bool Fixed::operator>	(const Fixed& fixed) { return ( this->rawValue > fixed.rawValue ); }
bool Fixed::operator<	(const Fixed& fixed) { return ( this->rawValue < fixed.rawValue ); }
bool Fixed::operator>=	(const Fixed& fixed) { return ( this->rawValue >= fixed.rawValue ); }
bool Fixed::operator<=	(const Fixed& fixed) { return ( this->rawValue <= fixed.rawValue ); }
bool Fixed::operator==	(const Fixed& fixed) { return ( this->rawValue == fixed.rawValue ); }
bool Fixed::operator!=	(const Fixed& fixed) { return ( this->rawValue != fixed.rawValue ); }

Fixed Fixed::operator+ (const Fixed& fixed) {
	Fixed newFixed;
	newFixed.setRawBits(this->rawValue + fixed.rawValue);
	return ( newFixed );
}

Fixed Fixed::operator- (const Fixed& fixed) {
	Fixed newFixed;
	newFixed.setRawBits(this->rawValue - fixed.rawValue);
	return ( newFixed ); 
}

Fixed Fixed::operator* (const Fixed& fixed) {
	Fixed newFixed;
	newFixed.setRawBits(this->rawValue * fixed.rawValue / (1 << 8));
	return ( newFixed ); 
}

Fixed Fixed::operator/ (const Fixed& fixed) {
	Fixed newFixed;
	newFixed.setRawBits(this->rawValue * (1 << 8) / fixed.rawValue);
	return ( newFixed ); 
}

Fixed& Fixed::operator++ ( void ) {
	this->rawValue++;
	return *this;
} // prefix

Fixed& Fixed::operator-- ( void ) {
	this->rawValue--;
	return *this;
} // prefix

Fixed Fixed::operator++( int ) {
	Fixed temp = *this;
	this->rawValue++;
	return temp;
} // postfix

Fixed Fixed::operator--( int ) {
	Fixed temp = *this;
	this->rawValue--;
	return temp;
} // postfix

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1.getRawBits() > fixed2.getRawBits())	
		return (fixed1);
	else											
		return (fixed2);
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())	
		return (fixed1);
	else											
		return (fixed2);
}

int Fixed::getRawBits( void ) const {
	return ( this->rawValue );
}

void Fixed::setRawBits( int const raw ) {
	this->rawValue = raw;
}

float Fixed::toFloat() const {
    return (static_cast<float>(this->rawValue) / (1 << this->fractionalBits));
}

int Fixed::toInt() const {
    return (static_cast<int>(this->rawValue) / (1 << this->fractionalBits));
}

std::ostream& operator<< (std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}