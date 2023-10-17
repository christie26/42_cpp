
#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "usage: ./btc <input>" << std::endl;
		return 0;
	}

	try {
		BitcoinExchange bit(av[1]);
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

}