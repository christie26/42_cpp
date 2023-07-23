
#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {

public:
	Harl( std::string level );
	void complain();
	enum Index {
        DEBUG,
        INFO,
        WARNING,
		ERROR
    };

private:
    void (Harl::*funcPtr[4])();

	std::string _level;

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

};

#endif