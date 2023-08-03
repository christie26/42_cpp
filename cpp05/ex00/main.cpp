
#include "Bureaucrat.hpp"

int main( void ) {

	Bureaucrat Alice("Alice", 3);
	Bureaucrat Daniel("Daniel", 148);
	Bureaucrat Bob("Bob", -1);
	Bureaucrat Chris("Chris", 170);
	
	std::cout << Alice << std::endl;
	std::cout << Daniel << std::endl;
	std::cout << Bob << std::endl;
	std::cout << Chris << std::endl;
	
	Alice.increaseGrade();
	Alice.increaseGrade();
	Alice.increaseGrade();

	Daniel.decreaseGrade();
	Daniel.decreaseGrade();
	Daniel.decreaseGrade();
	Daniel.decreaseGrade();

	return 0;
}