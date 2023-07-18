
#include <iostream>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}

void PhoneBook::addContact() {
	if (index > 8)
		index = index / 8;

	Contact new_contact;
	{
		std::cout << "Enter an firsname: ";
        std::cin >> myInt;
	}
	phone_book[index] = contact;
	index++;
}