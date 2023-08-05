
#include "ScalarConverter.hpp"

/*
Bureaucrat::Bureaucrat () {
	std::cout	<< Green << "Bureaucrat" << ", "
				<< Reset << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat ( const std::string name, int grade ) 
: _name ( name ) {
	std::cout	<< Green << "Bureaucrat" << ", "
				<< Reset << "Default constructor called" << std::endl;

	handleInvalidGrade(grade);
	_grade = grade;
}

Bureaucrat::~Bureaucrat () {
	std::cout	<< Red << "Bureaucrat" << ", "
				<< Reset << "Default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat ( const Bureaucrat &bureaucrat )  
: _name( bureaucrat._name ), _grade ( bureaucrat._grade ) {
	std::cout	<< Yellow << "Bureaucrat" << ", "
				<< Reset << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator= ( const Bureaucrat& bureaucrat ) {
	std::cout	<< Yellow << "Bureaucrat" << ", "
				<< Reset << "Copy assignment operator called" << std::endl;
	if (this != &bureaucrat) {
		const_cast<std::string&>(_name) = bureaucrat._name;
		_grade = bureaucrat._grade;
	}
	return *this;
}
*/