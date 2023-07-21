
#include <iostream>
#include <fstream>
#include "Sed.cpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Put 3 arguments, filename, s1, s2" << std::endl;
		exit(EXIT_FAILURE);
	}

	Sed sed = Sed(av[1], av[2], av[3]);

	std::string new_file = sed._filename + ".replace";

	std::ifstream ReadFile(sed._filename);
	if (!ReadFile.is_open()) {
    	std::cerr << "Error opening file: " << sed._filename << std::endl;
    	exit(EXIT_FAILURE);
	}
	std::ofstream WriteFile(new_file);
	if (!WriteFile.is_open()) {
    	std::cerr << "Error opening file: " << new_file << std::endl;
    	exit(EXIT_FAILURE);
	}
	
	std::string buffer;

	while (std::getline(ReadFile, buffer)) {
		size_t found = buffer.find(sed._s1);
		if (found!=std::string::npos) {
			
		}
	}


}