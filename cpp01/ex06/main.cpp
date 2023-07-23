
#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{

	if (ac != 2) {
		std::cout << "Harl Filter need one level" << std::endl;
		exit (EXIT_FAILURE);
	}

	Harl harl(av[1]);

	harl.complain();

	return 0;
}