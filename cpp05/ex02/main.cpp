
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void leak ( void ) {
	system("leaks a.out");
}
int main( void ) {

	PresidentialPardonForm John("John");
	PresidentialPardonForm Iann(John); // to check copy constructor

	ShrubberyCreationForm Thoma("Thoma");

	RobotomyRequestForm Eti("Eti");
	Bureaucrat Alice;
	Bureaucrat Bob;

	std::cout << John << std::endl;
	std::cout << Iann << std::endl;	
	std::cout << Thoma << std::endl;
	std::cout << Eti << std::endl;

	try { 
		Alice = Bureaucrat("Alice", 30);
		std::cout << Alice << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "Alice" << Red << e.what() << Reset << std::endl;
	}
	std::cout << std::endl;

	try { 
		Bob = Bureaucrat("Bob", 7);
		std::cout << Bob << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "Bob" << Red << e.what() << Reset << std::endl;
	}
	std::cout << std::endl;

	Bob.signForm(Thoma);
	Bob.signForm(John);
	Bob.signForm(Eti);

	Alice.executeForm(Thoma);
	Alice.executeForm(John);
	Bob.executeForm(John);
	Bob.executeForm(Eti);

	// atexit(&leak);
	return 0;
}
