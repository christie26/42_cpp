
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {

private:
	const std::string _name;
	int _grade;

public:

	Bureaucrat ( const std::string name, int grade );
	
	std::string getName() const ;
	int getGrade() const ;
	void increaseGrade();
	void decreaseGrade();

	void handleInvalidGrade( int grade );
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
