
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public Form {

private:
	std::string _target;

public:
	// RobotomyRequestForm ( void );
	RobotomyRequestForm ( std::string target );
	~RobotomyRequestForm( void );
	RobotomyRequestForm ( const RobotomyRequestForm &form );
	RobotomyRequestForm& operator= ( const RobotomyRequestForm& form );

	std::string getTarget( void ) const	;

	void execute(Bureaucrat const & executor) const;
};

#endif

