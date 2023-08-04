
#include "Form.hpp"

Form::Form () {
	std::cout	<< Green << "Form" << ", "
				<< Reset << "Default constructor called" << std::endl;
}

Form::Form ( const std::string name, int signGrade, int executeGrade ) 
: _name ( name ) {
	std::cout	<< Green << "Form" << ", "
				<< Reset << "Default constructor called" << std::endl;

	handleInvalidGrade(signGrade);
	_signGrade = signGrade;
	handleInvalidGrade(executeGrade);
	_executeGrade = executeGrade;
}

Form::~Form () {
	std::cout	<< Red << "Form" << ", "
				<< Reset << "Default destructor called" << std::endl;
}

Form::Form ( const Form &form )
: _name( form._name ), _signGrade ( form._signGrade ), _executeGrade ( form._executeGrade ) {
	std::cout	<< Yellow << "Form" << ", "
				<< Reset << "Copy constructor called" << std::endl;
}

Form& Form::operator= ( const Form& form ) {
	std::cout	<< Yellow << "Form" << ", "
				<< Reset << "Copy assignment operator called" << std::endl;
	if (this != &form) {
		const_cast<std::string&>(_name) = form._name;
		_signGrade = form._signGrade;
		_executeGrade = form._executeGrade;
	}
	return *this;
}

std::string Form::getName( void ) const	{ return _name; }
int Form::getSignGrade( void ) const	{ return _signGrade; }
int Form::getExecuteGrade( void ) const	{ return _executeGrade; }

void Form::beSigned( Bureaucrat& bureau ) {

	if (getSignGrade() < bureau.getGrade())
		throw std::invalid_argument(" bureau's grade is low to sign.");
    _signed = true;
}

void Form::handleInvalidGrade(int grade) {
    if (grade < 1)
        throw std::invalid_argument(" grade too high");
    else if (grade > 150)
        throw std::invalid_argument(" grade too low");
}

std::ostream& operator<< (std::ostream& os, const Form& bureaucrat) {
	os << bureaucrat.getName() << ", form sign grade: " << bureaucrat.getSignGrade() << ", "
		<< "execute grade: " << bureaucrat.getExecuteGrade() ;
	return (os);
}
