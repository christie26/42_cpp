
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void leak ( void ) {
	system("leaks a.out");
}

int main( void ) {

	Bureaucrat Alice;
	Intern a;
	Intern b(a);

	try {
		Alice = Bureaucrat("Alice", 30);
		std::cout << Alice << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "Alice" << Red << e.what() << Reset << std::endl;
	}
	std::cout << std::endl;

	Form* formPtr = b.makeForm("robo", "hey");

	Alice.signForm(*formPtr);
	Alice.executeForm(*formPtr);

	delete formPtr;

	// atexit(&leak);
	
	return 0;
}
