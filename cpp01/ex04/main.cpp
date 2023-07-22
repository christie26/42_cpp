
#include "StringSed.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << "Error: put three arguments" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	StringSed string = StringSed(av[1], av[2], av[3]);

	std::string new_file = string._filename.append(".replace", 0, 8);

	
	std::cout << "new file: " << new_file << std::endl;

	while (true) {
		
	}
	size_t found = 

	return 0;
}