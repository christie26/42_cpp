
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	const std::string _name;
	bool _signed;
	int _signGrade;
	int _executeGrade;

public:

	Form ( void );
	Form ( const std::string name, int signGrade, int executeGraded );
	~Form( void );
	Form (const Form &form);
	Form& operator= (const Form& form);

	std::string getName( void ) const ;
	int getSignGrade( void ) const ;
	int getExecuteGrade( void ) const ;

	void handleInvalidGrade( int grade );
	void beSigned( Bureaucrat& bureaucrat );
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
