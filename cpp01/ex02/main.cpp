
#include <string>
#include <iomanip>
#include <iostream>

// void leak() {
// 	system("leaks brain");
// }

int main() {

	std::string str = "HI THIS IS BRAIN";
	
	std::string *stringPTR;
	stringPTR = &str;

	std::string &stringREF = str;

	std::cout	<< "Print the memory address" 	<< std::endl
				<< "string:    " << str 		<< std::endl
				<< "stringPTR: " << *stringPTR	<< std::endl
				<< "stringREF: " << stringREF	<< std::endl
				<< std::endl;

	std::cout 	<< "Print the value of the string"	<< std::endl
			 	<< "string:    " << &str 			<< std::endl
			 	<< "stringPTR: " << stringPTR		<< std::endl
			 	<< "stringREF: " << &stringREF		<< std::endl
				<< std::endl;

	std::string str2 = str;
	std::cout	<< "str:  " << str << std::endl
				<< "str2: " << str2 << std::endl
				<< std::endl;

	str = "BYE";
	std::cout << "str -> BYE" << std::endl << std::endl;

	std::cout	<< "str:       "	<< str << std::endl
				<< "str2:      " 	<< str2 << std::endl
				<< "stringPTR: "	<< *stringPTR << std::endl
				<< "stringREF: "	<< stringREF << std::endl
				<< std::endl;

	// atexit(&leak);
}
