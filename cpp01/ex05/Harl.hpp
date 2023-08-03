
#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {

public:
	Harl();
	void complain( std::string level );

private:
    void (Harl::*funcPtr[4])(); // Array of pointers to member functions

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

};

#endif
