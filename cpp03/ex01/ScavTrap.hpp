
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

private: 
	bool guard;

public:
	ScavTrap(std::string name);
	~ScavTrap( void );
	
	void attack(const std::string& target);
	
	void guardGate();

};

#endif
