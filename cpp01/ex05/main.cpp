
#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("BLABLA");

	return 0;
}