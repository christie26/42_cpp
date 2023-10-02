
#include <iostream>
#include <fstream>
#include "Parser.hpp"
#include "Exchanger.hpp"

int main(int ac, char** av) {
	if (ac != 2) {
		std::cerr << "Error: put one argument." << std::endl;
		return 0;
	}

	try {
		Parser parser;
		Exchanger exchange(parser.getDatas(), av[1]);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

}