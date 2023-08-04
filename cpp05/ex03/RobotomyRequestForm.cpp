
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm ( void )
{
	std::cout	<< Green << "RobotomyRequestForm" << ", "
				<< Reset << "Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm ( std::string target )
: Form("robo", 72, 45), _target ( target ) {
	std::cout	<< Green << "RobotomyRequestForm" << ", "
				<< Reset << "Default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm () {
	std::cout	<< Red << "RobotomyRequestForm" << ", "
				<< Reset << "Default destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm ( const RobotomyRequestForm &form )
: Form(form), _target ( form._target ) {
	std::cout	<< Yellow << "RobotomyRequestForm" << ", "
				<< Reset << "Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator= ( const RobotomyRequestForm& form ) {
	std::cout	<< Yellow << "RobotomyRequestForm" << ", "
				<< Reset << "Copy assignment operator called" << std::endl;
	if (this != &form) {
		Form::operator=(form);
		_target = form.getTarget();
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget( void ) const	{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	
	if (!isSigned())
		throw std::invalid_argument("the form is not signed");
	
	handleInvalidGrade(getSignGrade() - executor.getGrade() + 1);

	std::cout << _target << " has been robotomized successfully 50\% of the time" << std::endl;
}

/*
RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> has been robotomized
successfully 50% of the time. Otherwise, informs that the robotomy failed
*/