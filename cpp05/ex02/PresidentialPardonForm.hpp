
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public Form {

private:
	std::string _target;

public:
	// PresidentialPardonForm ( void );
	PresidentialPardonForm ( std::string target );
	~PresidentialPardonForm( void );
	PresidentialPardonForm ( const PresidentialPardonForm &form );
	PresidentialPardonForm& operator= ( const PresidentialPardonForm& form );

	std::string getTarget( void ) const	;

	void execute(Bureaucrat const & executor) const;
};

#endif

