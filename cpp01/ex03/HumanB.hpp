
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {

public:
	HumanB( std::string name );

	const std::string&	getName();
	std::string			getWeapon();

	void				setWeapon(Weapon &weapon);
	void				attack();

private:
	std::string _name;
	Weapon		*_weapon;

};

#endif