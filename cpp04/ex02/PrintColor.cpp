
#include <iostream>
#include <string>

#include "PrintColor.hpp"

void printConstructor(std::string className) {
	
	std::cout << Green << className << ", "
			<< Reset << "Default constructor called" << std::endl;

}

void printDestructor(std::string className) {

	std::cout << Red << className << ", "
			<< Reset << "Default destructor called" << std::endl;

}

void printCopyConstructor(std::string className) {

	std::cout << Yellow << className << ", "
			<< Reset << "Copy constructor called" << std::endl;

}

// Copy assignment operator
void printCopyAssignmentOperator(std::string className) {

	std::cout << Yellow << className << ", "
			<< Reset << "Copy assignment operator called" << std::endl;

}

