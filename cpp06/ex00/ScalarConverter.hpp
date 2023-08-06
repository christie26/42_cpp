
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>

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
	ScalarConverter (const ScalarConverter &scalar);
	ScalarConverter& operator= (const ScalarConverter& scalar);

	static int getType( std::string str );
	// bool isChar ( std::string str );
	// bool isInt ( std::string str );
	// bool isFloat ( std::string str );
	// bool isDouble ( std::string str );

public:
	static void convert ( const std::string& str );
};

#endif
