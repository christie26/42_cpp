
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {

	Bureaucrat Alice;
	Form pipex;
	Form webserv;
	
	try { 
		pipex = Form("pipex", 5, 10);
		std::cout << pipex << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "pipex" << Red << e.what() << Reset << std::endl;
	}	std::cout << std::endl;
	
	try { 
		webserv = Form("webserv", 10, 10);
		std::cout << webserv << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "webserv" << Red << e.what() << Reset << std::endl;
	}	std::cout << std::endl;
	
	try { 
		Alice = Bureaucrat("Alice", 8);
		std::cout << Alice << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "Alice" << Red << e.what() << Reset << std::endl;
	}	std::cout << std::endl;

	Alice.signForm(webserv);
	Alice.signForm(pipex);
	Alice.increaseGrade();
	Alice.increaseGrade();
	Alice.increaseGrade();
	Alice.signForm(pipex);




	std::cout << std::endl;

	return 0;
}
