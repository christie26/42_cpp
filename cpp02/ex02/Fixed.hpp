
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

private:
	int rawValue;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed( const int intValue );
	Fixed( const float floatValue );
	Fixed( const Fixed &fixed );
	~Fixed();
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	
	Fixed&	operator= (const Fixed& fixed);
	
	bool operator>  (const Fixed& fixed);
	bool operator<  (const Fixed& fixed);
	bool operator>= (const Fixed& fixed);
	bool operator<= (const Fixed& fixed);
	bool operator== (const Fixed& fixed);
	bool operator!= (const Fixed& fixed);

	Fixed operator+ (const Fixed& fixed);
	Fixed operator- (const Fixed& fixed);
	Fixed operator* (const Fixed& fixed);
	Fixed operator/ (const Fixed& fixed);

	Fixed&	operator++ ( void );
	Fixed&	operator-- ( void );
	Fixed	operator++( int );
	Fixed	operator--( int );

	static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
	static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
	
/*
Add these four public overloaded member functions to your class:
• A static member function min that takes as parameters two references on fixed-point numbers, and returns a reference to the smallest one.
• A static member function min that takes as parameters two references to constant fixed-point numbers, and returns a reference to the smallest one.
*/

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif