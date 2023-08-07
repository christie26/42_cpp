
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public Form {

private:
	std::string _target;

public:
	ShrubberyCreationForm ( void );
	ShrubberyCreationForm ( std::string target );
	~ShrubberyCreationForm( void );
	ShrubberyCreationForm ( const ShrubberyCreationForm &form );
	ShrubberyCreationForm& operator= ( const ShrubberyCreationForm& form );

	std::string getTarget( void ) const	;

	void execute(Bureaucrat const & executor) const;
};

#endif

