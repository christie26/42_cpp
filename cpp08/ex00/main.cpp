
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>

#include "easyfind.hpp"



int main( void )
{
	/* set various containers */
	std::array<int, 6> intArray = {11, 12, 13, 14, 15, 11};
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
	int targetValue = 11;

	// /* test my easyfind */
	try {
		std::cout << "result: " << easyfind(intArray, targetValue) << std::endl;
		std::cout << "result: " << easyfind(intVector, targetValue) << std::endl;
		std::cout << "result: " << easyfind(intDeque, targetValue) << std::endl;
		std::cout << "result: " << easyfind(intList, targetValue) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
