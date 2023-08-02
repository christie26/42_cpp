
#include "Form.hpp"
#include "PrintColor.hpp"

Form::Form ( const std::string name, int signGrade, int executeGrade ) 
: _name ( name ) {
	printConstructor("Form");

    try {
        handleInvalidGrade(signGrade);
        _signGrade = signGrade;
        handleInvalidGrade(executeGrade);
        _executeGrade = executeGrade;
    } catch (std::exception &e) {
        std::cout << _name << Red << e.what() << Reset << std::endl;
        _signGrade = 150;
    }
}

std::string Form::getName( void ) const	{ return _name; }
int Form::getSignGrade( void ) const	{ return _signGrade; }
int Form::getExecuteGrade( void ) const	{ return _executeGrade; }

void Form::beSigned( Bureaucrat& bureau ) {

    handleInvalidGrade(getSignGrade() - bureau.getGrade() + 1);
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