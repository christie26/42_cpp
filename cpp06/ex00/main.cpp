
#include "ScalarConverter.hpp"

int main( int ac, char **av ) {

	if (ac != 2) {
		std::cout << "Error: put only one argument !" << std::endl;
		return (1);
	} else if (av[1][0] == 0) {
		std::cout << "Error: input is empty !" << std::endl;
		return (1);
	}

	ScalarConverter::convert(av[1]);

	return 0;
}