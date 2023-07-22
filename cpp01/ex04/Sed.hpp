
#ifndef SED_HPP
#define SED_HPP

#include <string>

class Sed {

public:
	Sed(std::string filename, std::string s1, std::string s2);

	std::string _filename;
	std::string _s1;
	std::string _s2;

private:

};

#endif