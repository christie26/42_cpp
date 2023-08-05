#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define Black "\033[1;30m"
#define Red "\033[1;31m"
#define Green "\033[1;32m"
#define Yellow "\033[1;33m"
#define Blue "\033[1;34m"
#define Magenta "\033[1;35m"
#define Cyan "\033[1;36m"
#define White "\033[1;37m"
#define Reset "\033[1;0m"

class ClapTrap {

protected:
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
	bool		stillAlive( void );
	void		printStatus( void );

public:
	ClapTrap( std::string name );
	virtual ~ClapTrap( void );
	ClapTrap ( const ClapTrap &clapTrap );
	ClapTrap& operator= ( const ClapTrap& clapTrap );

	virtual void attack( const std::string& target );
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void setAttackDamage(int amount);

};

#endif
