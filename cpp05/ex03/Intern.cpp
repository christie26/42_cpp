
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern () {
	std::cout	<< Green << "Intern" << ", "
				<< Reset << "Default constructor called" << std::endl;
}

Intern::~Intern () {
	std::cout	<< Red << "Intern" << ", "
				<< Reset << "Default destructor called" << std::endl;
}

Intern::Intern ( const Intern& ) {
	std::cout	<< Yellow << "Intern" << ", "
				<< Reset << "Copy constructor called" << std::endl;
}

Intern& Intern::operator= ( const Intern& ) {
	std::cout	<< Yellow << "Intern" << ", "
				<< Reset << "Copy assignment operator called" << std::endl;
	return *this;
}

Form* Intern::makeForm( std::string nameForm, std::string targetForm ) {

	Form* formPtr = 0; 

    if (nameForm == "president") {
        formPtr = new PresidentialPardonForm(targetForm);
    } else if (nameForm == "robo") {
        formPtr = new RobotomyRequestForm(targetForm);
    } else if (nameForm == "shrubbery") {
        formPtr = new ShrubberyCreationForm(targetForm);
    } else {
        std::cout << "This name, " << nameForm << " doesn't exist." << std::endl;
        return nullptr;
	}
	std::cout << "Intern creates " << nameForm << std::endl;
	return formPtr;
}
