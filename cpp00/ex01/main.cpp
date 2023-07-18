
#include <iostream>

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
	
	PhoneBook myPhonebook;

	while (true) {
	
		std::string input;
		
		std::cout << "Enter your command: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
      		std::clearerr(stdin);
			std::cout << std::endl;
      		std::cin.clear();
			continue ;
		}
		if (input == "ADD")
			myPhonebook.AddContact();
		else if (input == "SEARCH")
			myPhonebook.SearchContact();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "WRONG COMMAND" << std::endl;
	}
	return 0;
}
