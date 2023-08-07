
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <limits>

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

class ScalarConverter {

private:
	ScalarConverter ( void );
	~ScalarConverter( void );
	ScalarConverter ( const ScalarConverter& );
	ScalarConverter& operator= ( const ScalarConverter& );

	static int typeDetector( const std::string& str );
	static int handlePseudo( const std::string& str);
	static void convertEachType ( int type );

public:
	static int		_intValue;
	static char		_charValue;
	static float	_floatValue;
	static double	_doubleValue;

	static void convert ( const std::string& str );
};

#endif
