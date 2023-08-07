
#ifndef Form_HPP
#define Form_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

#define HIGHEXCEPTION "grade too high"
#define LOWEXCEPTION "grade too low"
#define UNSIGNED " is unsigned"

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
	class UnSigned : public std::exception {
		public:
    		const char* what() const throw();
	};

	Form ( void );
	Form ( const std::string name, int signGrade, int executeGraded );
	virtual ~Form( void );
	Form ( const Form &form );
	Form& operator= ( const Form& form );

	std::string getName( void ) const ;
	int getSignGrade( void ) const ;
	int getExecuteGrade( void ) const ;

	void handleInvalidGrade( int grade ) const;
	void beSigned( Bureaucrat& bureaucrat );
	int isSigned( void ) const ;

	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<( std::ostream& os, const Form& form );

#endif
