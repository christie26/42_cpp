
#ifndef STRINGSED_HPP
# define STRINGSED_HPP

#include <string>

class StringSed {

public:
	StringSed(std::string filename, std::string s1, std::string s2);
	
	std::string _filename;
	std::string _s1;
	std::string _s2;

private:

};

#endif