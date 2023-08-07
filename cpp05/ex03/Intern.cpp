
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern () {
	std::cout	<< Green << "Intern" << ", "
				<< Reset << "Default constructor called" << std::endl;
	funcPtr[0] = &Intern::createPresident;
    funcPtr[1] = &Intern::createRobo;
    funcPtr[2] = &Intern::createShrubbery;
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

Form* Intern::makeForm(std::string nameForm, std::string targetForm) {

	std::string stringArray[3] = { "president", "robo", "shrubbery" };

    for (int i = 0; i < 3; i++) {
        if (nameForm == stringArray[i]) {
            Form* formPtr = (this->*funcPtr[i])(targetForm);
            std::cout << "Intern creates " << nameForm << std::endl;
			return formPtr;
        }
    }
    std::cout << "This name, " << nameForm << " doesn't exist." << std::endl;
    return NULL;
}

Form* Intern::createPresident( std::string targetForm ) {
	return (new PresidentialPardonForm(targetForm));
}

Form* Intern::createRobo( std::string targetForm ) {
	return (new RobotomyRequestForm(targetForm));
}

Form* Intern::createShrubbery( std::string targetForm ) {
	return (new ShrubberyCreationForm(targetForm));
}
