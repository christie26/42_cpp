
#include "Harl.hpp"
#include <iostream>

Harl::Harl( std::string level ) : _level(level) {
    funcPtr[0] = &Harl::debug;
    funcPtr[1] = &Harl::info;
    funcPtr[2] = &Harl::warning;
    funcPtr[3] = &Harl::error;
}

int Harl::getIndex ( ) {
    
    int index = -1;

    if (this->_level == "DEBUG")
        index = DEBUG;
    if (this->_level == "INFO")
        index = INFO;
    if (this->_level == "WARNING")
        index = WARNING;
    if (this->_level == "ERROR")
        index = ERROR;
    
    return (index);
}

void Harl::complain( ) {
    
    switch (getIndex()) {
        case DEBUG:
            (this->*funcPtr[DEBUG])();
        case INFO:
            (this->*funcPtr[INFO])();
        case WARNING:
            (this->*funcPtr[WARNING])();
        case ERROR:
            (this->*funcPtr[ERROR])();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

void Harl::debug( void ) {
    std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
    std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
    << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\n"
    << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
    std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
