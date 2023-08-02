
#include "Bureaucrat.hpp"
#include "PrintColor.hpp"

Bureaucrat::Bureaucrat ( const std::string name, int grade ) 
: _name ( name ) {
	printConstructor("Bureaucrat");

    try {
        handleInvalidGrade(grade);
        _grade = grade;
    } catch (std::exception &e) {
        std::cout << _name << Red << e.what() << Reset << std::endl;
        _grade = 150;
    }
}

std::string Bureaucrat::getName( void ) const {
	return _name;
}

int Bureaucrat::getGrade( void ) const {
	return _grade;
}

void Bureaucrat::increaseGrade() {

	try {
		handleInvalidGrade(_grade - 1);
		_grade--;
		std::cout << *this << std::endl;
	} catch (std::exception &e) {
        std::cout << _name << Red << e.what() << Reset << " to increase" << std::endl;
		std::cout << *this << std::endl;
    }
}

void Bureaucrat::decreaseGrade() {

	try {
		handleInvalidGrade(_grade + 1);
		_grade++;
		std::cout << *this << std::endl;
	} catch (std::exception &e) {
        std::cout << _name << Red << e.what() << Reset << " to decrease" << std::endl;
		std::cout << *this << std::endl;
    }
}

void Bureaucrat::handleInvalidGrade(int grade) {
    if (grade < 1)
        throw std::invalid_argument(" grade too high");
    else if (grade > 150)
        throw std::invalid_argument(" grade too low");
}

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
