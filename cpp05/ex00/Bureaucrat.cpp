
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( const std::string name, int grade ) 
: _name ( name ) {

	try {
		if ( grade < 1 )
			throw std::string (" is too high");
		else if ( grade > 150 )
			throw std::string (" is too low");
		_grade = grade;
	}
	catch (const std::string errorMessage) {
		std::cerr << "Error: " << grade << errorMessage << std::endl;
		std::cerr << "I will put 150 as grade" << std::endl;
		_grade = 150; // put lowest grade in case of exception
	}

}

std::string Bureaucrat::getName( void ) const {
	return _name;
}

int Bureaucrat::getGrade( void ) const {
	return _grade;
}

void Bureaucrat::increaseGrade() {
	_grade--;
}

void Bureaucrat::decreaseGrade() {
	_grade++;
}

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() ;
	return (os);
}