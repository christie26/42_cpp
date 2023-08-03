
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

#define Red "\033[1;31m"
#define Green "\033[1;32m"
#define Yellow "\033[1;33m"
#define Blue "\033[1;34m"
#define Reset "\033[1;0m"

class AForm;

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
	void signForm( AForm& form );

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
