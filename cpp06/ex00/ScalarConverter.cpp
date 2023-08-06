
#include "ScalarConverter.hpp"

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
// int		intValue;
// char	charValue;
// float	floatValue;
// double	doubleValue;

void ScalarConverter::convert( const std::string& str ) {

	int type = getType(str);

	(void)(type);
	// if (type == INT)
		// intCenter(str);
	
}
