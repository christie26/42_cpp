
#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <fstream>
#include <iostream>

class Sed {

public:
	Sed(std::string filename, std::string s1, std::string s2);

	std::ifstream getReadFile ();
	std::ofstream getWriteFile ();
	void copyRoutine(std::ifstream &ReadFile, std::ofstream &WriteFile);

private:

	std::string _filename;
	std::string _s1;
	std::string _s2;

};

#endif