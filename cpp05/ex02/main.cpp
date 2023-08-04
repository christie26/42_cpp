
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void ) {

	PresidentialPardonForm John;
	Bureaucrat Alice;

	try { 
		John = PresidentialPardonForm("John");
		std::cout << John << std::endl;
		PresidentialPardonForm Iann(John); // to check copy constructor
		std::cout << Iann << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "John" << Red << e.what() << Reset << std::endl;
	}
	
	try { 
		Alice = Bureaucrat("Alice", 7);
		std::cout << Alice << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "Alice" << Red << e.what() << Reset << std::endl;
	}

	Alice.executeForm(John);

	return 0;
}
