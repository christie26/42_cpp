#include "RPN.hpp"
#include <string>
#include <iostream>

int main(int ac, char** av) {

	std::string str;
	for (int i = 1; i < ac; i++) {
		str += av[i];
		str += " ";
	}
	RPN rpn(str);
}