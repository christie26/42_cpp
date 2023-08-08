
#include <iostream>
#include <string>

#include "Array.hpp"

int main( void )
{
    
	Array<std::string> stringArray(10);

	stringArray[0] = "happy";
	stringArray[1] = "paris";
	stringArray[2] = "2023";

	std::cout << "stringArray[0]: " << stringArray[0] << std::endl;
	std::cout << "stringArray[1]: " << stringArray[1] << std::endl;
	std::cout << "stringArray[2]: " << stringArray[2] << std::endl;
	std::cout << std::endl;

	Array<std::string> copy1(stringArray);

	std::cout << "copy1[0]: " << copy1[0] << std::endl;
	std::cout << "copy1[1]: " << copy1[1] << std::endl;
	std::cout << "copy1[2]: " << copy1[2] << std::endl;
	std::cout << std::endl;
    
	Array<std::string> copy2;
	copy2 = stringArray;

	std::cout << "copy2[0]: " << copy2[0] << std::endl;
	std::cout << "copy2[1]: " << copy2[1] << std::endl;
	std::cout << "copy2[2]: " << copy2[2] << std::endl;
	
	return 0;
}
