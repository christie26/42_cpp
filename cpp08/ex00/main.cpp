
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

#include "easyfind.hpp"

int main( void )
{
	/* set various containers */
	std::vector<int> intVector;
	std::deque<int> intDeque;
	std::list<int> intList;

    for (int i = 11; i < 16; i++) {
        intVector.push_back(i);
        intDeque.push_back(i);
        intList.push_back(i);
	}
	intVector.push_back(11);
	intDeque.push_back(11);
	intList.push_back(11);

	/* set target value */
	int targetValue = 12;

	/* test my easyfind */
	std::vector<int>::const_iterator itV = easyfind(intVector, targetValue);
	std::deque<int>::const_iterator itD = easyfind(intDeque, targetValue);
	std::list<int>::const_iterator itL = easyfind(intList, targetValue);
	
	if (itV != intVector.end()) {
		std::cout << "We found " << *itV << " in " << std::distance(intVector.cbegin(), itV) << "th." << std::endl;
	} else {
		std::cout << "We can't find it." << std::endl;
	}
	if (itD != intDeque.end()) {
		std::cout << "We found " << *itD << " in " << std::distance(intDeque.cbegin(), itD) << "th." << std::endl;
	} else {
		std::cout << "We can't find it." << std::endl;
	}
	if (itL != intList.end()) {
		std::cout << "We found " << *itL << " in " << std::distance(intList.cbegin(), itL) << "th." << std::endl;
	} else {
		std::cout << "We can't find it." << std::endl;
	}

	return 0;
}
