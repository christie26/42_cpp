
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

#define Red "\033[1;31m"
#define Green "\033[1;32m"
#define Yellow "\033[1;33m"
#define Blue "\033[1;34m"
#define Reset "\033[1;0m"

class Intern {

private:

public:

	Intern ( void );
	~Intern( void );
	Intern ( const Intern &intern );
	Intern& operator= ( const Intern& intern );

	Form* makeForm( std::string nameForm, std::string targetForm );

};


#endif
