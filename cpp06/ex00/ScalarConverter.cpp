
#include "ScalarConverter.hpp"

// lazy initialization
int ScalarConverter::_intValue;
char ScalarConverter::_charValue;
float ScalarConverter::_floatValue;
double ScalarConverter::_doubleValue;

ScalarConverter::ScalarConverter () {
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter () {
	std::cout << "Default destructor called" << std::endl;
}

ScalarConverter::ScalarConverter ( const ScalarConverter& ) {
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator= ( const ScalarConverter& ) {
	std::cout << "Copy assignment operator called" << std::endl;
	std::cout << "StaticClass copy assignment is not supported." << std::endl;
	return *this;
}

/*----------------------------------------------------*/

void ScalarConverter::convert( const std::string& str ) {

	int type = typeDetector(str);

	// std::cout << "type is " << type << std::endl;

	// if (type == INT)
	// 	std::cout << "int is " << _intValue << std::endl;
	// if (type == CHAR)
	// 	std::cout << "char is " << _charValue << std::endl;
	// if (type == FLOAT)
	// 	std::cout << "float is " << _floatValue << std::endl;
	// if (type == DOUBLE)
	// 	std::cout << "double is " << _doubleValue << std::endl;

	convertEachType(type);	
	
}
