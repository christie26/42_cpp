
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {

	Form* pipex;
	Form* webserv;
	
	try { 
		pipex = new Form("pipex", 5, 10);
		std::cout << *pipex << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "pipex " << Red << e.what() << Reset << std::endl;
		pipex = NULL;
	}	std::cout << std::endl;

	try { 
		webserv = new Form("webserv", 10, 10);
		std::cout << *webserv << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "webserv " << Red << e.what() << Reset << std::endl;
		webserv = NULL;
	}	std::cout << std::endl;
	
	Bureaucrat Alice;

	try { 
		Alice = Bureaucrat("Alice", 7);
		/* un-comment below to sign pipex */
		// Alice.increaseGrade();
		// Alice.increaseGrade();
		// Alice.increaseGrade();
		std::cout << Alice << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "Alice" << Red << e.what() << Reset << std::endl;
	}	std::cout << std::endl;

	if (pipex) {
		Alice.signForm(*pipex);
		delete pipex;
	}
	if (webserv){
		Alice.signForm(*webserv);
		delete webserv;
	}
	return 0;
}
