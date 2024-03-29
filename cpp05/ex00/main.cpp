
#include "Bureaucrat.hpp"

void leak ( void ) {
	system("leaks a.out");
}

int main( void ) {

	Bureaucrat Alice;
	Bureaucrat Daniel;
	Bureaucrat Bob;
	Bureaucrat Chris;

	try { 
		Alice = Bureaucrat("Alice", 10);
		std::cout << Alice << std::endl;
		Alice.increaseGrade();
		Alice.increaseGrade();
		Alice.increaseGrade();
		std::cout << Alice << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "Alice " << Red << e.what() << Reset << std::endl;
	}
	std::cout << std::endl;

	try { 
		Daniel = Bureaucrat("Daniel", 148);
		std::cout << Daniel << std::endl;
		Daniel.decreaseGrade();
		Daniel.decreaseGrade();
		Daniel.decreaseGrade();
		Daniel.decreaseGrade();
	} catch ( std::exception &e ) {
		std::cout << "Daniel " << Red << e.what() << Reset << std::endl;
	}
	std::cout << std::endl;

	try {
		Bob = Bureaucrat("Bob", -1);
	} catch ( std::exception &e ) {
		std::cout << "Bob " << Red << e.what() << Reset << std::endl;
	}
	std::cout << std::endl;
	
	try { 
		Chris = Bureaucrat("Chris", 170);
	} catch ( std::exception &e ) {
		std::cout << "Chris " << Red << e.what() << Reset << std::endl;
	}
	std::cout << std::endl;

	// atexit(&leak);

	return 0;
}