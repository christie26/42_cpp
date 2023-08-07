
#include "Form.hpp"

Form::Form ( const std::string name, const int signGrade, const int executeGrade ) 
: _name ( name ), _signed( false ), _signGrade(signGrade), _executeGrade(executeGrade) {
	std::cout	<< Green << "Form" << ", "
				<< Reset << "Default constructor called" << std::endl;

	handleInvalidGrade(signGrade);
	handleInvalidGrade(executeGrade);
}

Form::~Form () {
	std::cout	<< Red << "Form" << ", "
				<< Reset << "Default destructor called" << std::endl;
}

Form::Form ( const Form &form )
: _name( form._name ), _signed( form._signed ), _signGrade ( form._signGrade ), _executeGrade ( form._executeGrade ) {
	std::cout	<< Yellow << "Form" << ", "
				<< Reset << "Copy constructor called" << std::endl;
}

Form& Form::operator= ( const Form& form ) {
	std::cout	<< Yellow << "Form" << ", "
				<< Reset << "Copy assignment operator called" << std::endl;
	if (this != &form) {
		// not recommended
		const_cast<std::string&>(_name) = form._name;
		_signed = form._signed;
		const_cast<int&>(_signGrade) = form._signGrade;
		const_cast<int&>(_executeGrade) = form._executeGrade;
	}
	return *this;
}

const char* Form::GradeTooHighException::what() const throw () { return HIGHEXCEPTION; }
const char* Form::GradeTooLowException::what() const throw () { return LOWEXCEPTION; }

std::string Form::getName( void ) const	{ return _name; }
int Form::getSignGrade( void ) const	{ return _signGrade; }
int Form::getExecuteGrade( void ) const	{ return _executeGrade; }

void Form::beSigned( Bureaucrat& bureau ) {

	if (getSignGrade() < bureau.getGrade())
		throw GradeTooLowException();
    _signed = true;
}

void Form::handleInvalidGrade(int grade) {
    if (grade < 1)
		throw GradeTooHighException();
    else if (grade > 150)
		throw GradeTooLowException();
}

std::ostream& operator<< (std::ostream& os, const Form& bureaucrat) {
	os << bureaucrat.getName() << ", form sign grade: " << bureaucrat.getSignGrade() << ", "
		<< "execute grade: " << bureaucrat.getExecuteGrade() ;
	return (os);
}
