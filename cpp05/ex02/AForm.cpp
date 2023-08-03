
#include "AForm.hpp"

AForm::AForm () {
	std::cout	<< Green << "AForm" << ", "
				<< Reset << "Default constructor called" << std::endl;
}

AForm::AForm ( const std::string name, int signGrade, int executeGrade ) 
: _name ( name ) {
	std::cout	<< Green << "AForm" << ", "
				<< Reset << "Default constructor called" << std::endl;

	handleInvalidGrade(signGrade);
	_signGrade = signGrade;
	handleInvalidGrade(executeGrade);
	_executeGrade = executeGrade;
}

AForm::~AForm () {
	std::cout	<< Red << "AForm" << ", "
				<< Reset << "Default destructor called" << std::endl;
}

AForm::AForm ( const AForm &form )
: _name( form._name ), _signGrade ( form._signGrade ), _executeGrade ( form._executeGrade ) {
	std::cout	<< Yellow << "AForm" << ", "
				<< Reset << "Copy constructor called" << std::endl;
}

AForm& AForm::operator= ( const AForm& form ) {
	std::cout	<< Yellow << "AForm" << ", "
				<< Reset << "Copy assignment operator called" << std::endl;
	if (this != &form) {
		const_cast<std::string&>(_name) = form._name;
		_signGrade = form._signGrade;
		_executeGrade = form._executeGrade;
	}
	return *this;
}

std::string AForm::getName( void ) const	{ return _name; }
int AForm::getSignGrade( void ) const		{ return _signGrade; }
int AForm::getExecuteGrade( void ) const	{ return _executeGrade; }

void AForm::beSigned( Bureaucrat& bureau ) {

    handleInvalidGrade(getSignGrade() - bureau.getGrade() + 1);
    _signed = true;
}

void AForm::handleInvalidGrade(int grade) {
    if (grade < 1)
        throw std::invalid_argument(" grade too high");
    else if (grade > 150)
        throw std::invalid_argument(" grade too low");
}

std::ostream& operator<< (std::ostream& os, const AForm& bureaucrat) {
	os << bureaucrat.getName() << ", form sign grade: " << bureaucrat.getSignGrade() << ", "
		<< "execute grade: " << bureaucrat.getExecuteGrade() ;
	return (os);
}
