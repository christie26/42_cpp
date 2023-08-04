
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void ) {

	PresidentialPardonForm John;
	ShrubberyCreationForm Thoma;
	RobotomyRequestForm Eti;
	Bureaucrat Alice;
	Bureaucrat Bob;

	try { 
		John = PresidentialPardonForm("John");
		std::cout << John << std::endl;
		PresidentialPardonForm Iann(John); // to check copy constructor
		std::cout << Iann << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "John" << Red << e.what() << Reset << std::endl;
	}
	std::cout << std::endl;
	
	try { 
		Thoma = ShrubberyCreationForm("thoma");
		std::cout << Thoma << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "Thoma" << Red << e.what() << Reset << std::endl;
	}
	std::cout << std::endl;

	try { 
		Eti = RobotomyRequestForm("eti");
		std::cout << Eti << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "eti" << Red << e.what() << Reset << std::endl;
	}
	std::cout << std::endl;

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
	Bob.executeForm(John);
	Bob.executeForm(Eti);

	return 0;
}
