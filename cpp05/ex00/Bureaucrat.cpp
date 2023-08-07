
#include "Bureaucrat.hpp"

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

const char* Bureaucrat::GradeTooHighException::what() const throw () { return HIGHEXCEPTION; }
const char* Bureaucrat::GradeTooLowException::what() const throw () { return LOWEXCEPTION; }

std::string Bureaucrat::getName( void ) const {
	return _name;
}

int Bureaucrat::getGrade( void ) const {
	return _grade;
}

void Bureaucrat::increaseGrade() {

	handleInvalidGrade(_grade - 1);
	_grade--;
}

void Bureaucrat::decreaseGrade() {

	handleInvalidGrade(_grade + 1);
	_grade++;
}

void Bureaucrat::handleInvalidGrade( int grade ) {
    if (grade < 1)
		throw GradeTooHighException();
    else if (grade > 150)
		throw GradeTooLowException();
}

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
