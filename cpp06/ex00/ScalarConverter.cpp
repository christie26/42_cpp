
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter () {
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter () {
	std::cout << "Default destructor called" << std::endl;
}

ScalarConverter::ScalarConverter ( const ScalarConverter &scalar ) {
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator= ( const ScalarConverter& scalar ) {
	std::cout << "Copy assignment operator called" << std::endl;
	std::cout << "StaticClass copy assignment is not supported." << std::endl;
}

int getType( std::string str ) {
	
}

void ScalarConverter::convert( std::string str ) {

}