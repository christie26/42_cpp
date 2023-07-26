
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {

private:

	int value;
	static const int fractionalBits = 8;

public:

	Fixed();
	~Fixed();
	Fixed (Fixed &fixed); // copy constructor 
	Fixed& operator= (const Fixed& fixed); // copy assignment operator overload

	// const member function
	int getRawBits( void ) const;
	// get const variable as parameter 
	void setRawBits( int const raw );

};

#endif