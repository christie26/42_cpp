
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

#define HIGHEXCEPTION "grade too high"
#define LOWEXCEPTION "grade too low"

class Bureaucrat;

class Form {

private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _executeGrade;

public:

	class GradeTooHighException : public std::exception {
		public:
    		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
    		const char* what() const throw();
	};

	Form ( void );
	Form ( const std::string name, const int signGrade, const int executeGraded );
	~Form( void );
	Form (const Form &form);
	Form& operator= (const Form& form);

	std::string getName( void ) const ;
	int getSignGrade( void ) const ;
	int getExecuteGrade( void ) const ;

	static void handleInvalidGrade( int grade );
	void beSigned( Bureaucrat& bureaucrat );

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
