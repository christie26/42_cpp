
#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private:
	const std::string _name;
	bool _signed;
	int _signGrade;
	int _executeGrade;

public:

	AForm ( void );
	AForm ( const std::string name, int signGrade, int executeGraded );
	~AForm( void );
	AForm (const AForm &form);
	AForm& operator= (const AForm& form);

	std::string getName( void ) const ;
	int getSignGrade( void ) const ;
	int getExecuteGrade( void ) const ;

	void handleInvalidGrade( int grade );
	void beSigned( Bureaucrat& bureaucrat );
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
