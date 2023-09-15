
#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement( const T e ) {
	std::cout << e << std::endl;
}

template <typename T>
void doubleElement( T e ) {
	e  = e + e;
}

int main( void ) {
	
	double intArray[5] = {0, 1, 2, 3, 4};
	std::string stringArray[5] = {"happy", "yeah", "how are you ?", "42", "seoul"};

	iter(stringArray, sizeof(stringArray) / sizeof(stringArray[0]), &printElement<int>);
	// iter(stringArray, sizeof(stringArray) / sizeof(stringArray[0]), &printElement<const int>);
	// std::cout << std::endl;
	
	// iter(intArray, sizeof(intArray) / sizeof(intArray[0]), &printElement);
	// std::cout << std::endl;

	// iter(intArray, sizeof(intArray) / sizeof(intArray[0]), &doubleElement);
	// iter(intArray, sizeof(intArray) / sizeof(intArray[0]), &printElement);

	return 0;
}
