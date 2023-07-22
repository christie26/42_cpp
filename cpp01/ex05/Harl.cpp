
#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
    funcPtr[0] = &Harl::debug;
    funcPtr[1] = &Harl::info;
    funcPtr[2] = &Harl::warning;
    funcPtr[3] = &Harl::error;
}

void Harl::complain(std::string level) {
    int index = -1;

    if (level == "DEBUG")
        index = DEBUG;
    if (level == "INFO")
        index = INFO;
    if (level == "WARNING")
        index = WARNING;
    if (level == "ERROR")
        index = ERROR;

    if (index == -1) {
        std::cout << "Invalid complaint level." << std::endl;
        return ;
    }
    
    (this->*funcPtr[index])();
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
