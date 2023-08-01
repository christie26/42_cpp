
#include <iostream>

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
	
	PhoneBook myPhonebook;

	while (true) {
	
		std::string input;
		
		std::cout << "Enter your command: ";

		input = myPhonebook.getInput();
		
		if (input == "ADD")
			myPhonebook.AddContact();
		else if (input == "SEARCH")
			myPhonebook.SearchContact();
		else if (input == "EXIT")
			break ;
		else if (!input.length())
      		continue;
    	else
			std::cout << "WRONG COMMAND" << std::endl;
	}
	return 0;
}
