
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {

	Bureaucrat Alice("Alice", 3);
	Bureaucrat Bob("Bob", 10);
	
	std::cout << Alice << std::endl;
	std::cout << Bob << std::endl;
	
	Alice.increaseGrade();
	Alice.increaseGrade();
	Alice.increaseGrade();

	std::cout << std::endl;

	Form pipex("pipex", 5, 0);
	Form webserv("webserv", 5, 10);
	std::cout << pipex << std::endl;
	std::cout << webserv << std::endl;

	Alice.signForm(webserv);
	Bob.signForm(webserv);

	std::cout << std::endl;

	Bob.increaseGrade();
	Bob.increaseGrade();
	Bob.increaseGrade();
	Bob.increaseGrade();
	Bob.increaseGrade();
	Bob.signForm(webserv);
	
	return 0;
}
