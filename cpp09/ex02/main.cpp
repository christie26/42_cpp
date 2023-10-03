#include <string>
#include <iostream>
#include "PmergeMe.hpp"

int main(int ac, char** av) {

	std::string str;
	for (int i = 1; i < ac; i++) {
		str += av[i];
		str += " ";
	}
	while (*(str.end() - 1) == ' ') {
		str.pop_back();
	}
	PmergeMe pmergeme(str);
}
