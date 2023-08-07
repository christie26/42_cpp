
#include "PresidentialPardonForm.hpp"

// PresidentialPardonForm::PresidentialPardonForm ( void )
// {
// 	std::cout	<< Green << "PresidentialPardonForm" << ", "
// 				<< Reset << "Default constructor called" << std::endl;
// }

PresidentialPardonForm::PresidentialPardonForm ( std::string target )
: Form("president", 25, 5), _target ( target ) {
	std::cout	<< Green << "PresidentialPardonForm" << ", "
				<< Reset << "Default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm () {
	std::cout	<< Red << "PresidentialPardonForm" << ", "
				<< Reset << "Default destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm ( const PresidentialPardonForm &form )
: Form(form), _target ( form._target ) {
	std::cout	<< Yellow << "PresidentialPardonForm" << ", "
				<< Reset << "Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator= ( const PresidentialPardonForm& form ) {
	std::cout	<< Yellow << "PresidentialPardonForm" << ", "
				<< Reset << "Copy assignment operator called" << std::endl;
	if (this != &form) {
		Form::operator=(form);
		_target = form.getTarget();
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget( void ) const	{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	
	if (!isSigned())
		throw UnSigned();
	
	handleInvalidGrade(getSignGrade() - executor.getGrade() + 1);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
