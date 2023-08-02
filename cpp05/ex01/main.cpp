
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {

	Bureaucrat Alice("Alice", 3);
	Bureaucrat Bob("Bob", -1);
	
	std::cout << Alice << std::endl;
	std::cout << Bob << std::endl;
	
	Alice.increaseGrade();
	Alice.increaseGrade();
	Alice.increaseGrade();

	Form webserv("webserv", 5, 10);

	Alice.signForm(webserv);
	
	return 0;
}
