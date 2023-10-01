
#include <iostream>
#include <fstream>
#include "Parser.hpp"

int main(int ac, char** av) {
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 0;
	}
	std::ifstream fs;
	fs.open (av[1]);
	std::string av_1 = av[1];
	if (!fs.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return 0;
	}
	try {
		Parser parser;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}