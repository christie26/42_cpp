
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( const std::string name, int grade ) 
: _name ( name ) {

	try {
		if ( grade < 1 )
		 	throw std::invalid_argument("high");
		else if ( grade > 150 )
		 	throw std::invalid_argument("low");
		_grade = grade;
	}
	catch (std::exception & e) {
		if (!std::strcmp(e.what(), "high"))
			GradeTooHighException();
		else if (!std::strcmp(e.what(), "low"))
			GradeTooLowException();
		// std::cerr << "Error: " << grade << e.what() << std::endl; // what: returns an explanatory string
		// std::cerr << "I will put 150 as grade" << std::endl;
		_grade = 150; // put lowest grade in case of exception
	}

}

void Bureaucrat::GradeTooHighException ( void ) {
	std::cerr << _name << " can't have too high grade." << std::endl;
}

void Bureaucrat::GradeTooLowException ( void ) {
	std::cerr << _name << " can't have too low grade." << std::endl;
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
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
