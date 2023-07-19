
#include <iostream>
#include <iomanip>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}

void PhoneBook::AddContact() {

	Contact 	newContact;
	std::string	input;

	while (true) {
		std::cout << "Your first name: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
      		std::clearerr(stdin);
			std::cout << std::endl;
      		std::cin.clear();
		}
		if (!input.empty()) {
			newContact.setFirstname(input);
			break ;
		}
	}
	
	while (true) {
		std::cout << "Your last name: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
      		std::clearerr(stdin);
			std::cout << std::endl;
      		std::cin.clear();
		}
		if (!input.empty()) {
			newContact.setLastname(input);
			break ;
		}
	}

	while (true) {
		std::cout << "Your nick name: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
      		std::clearerr(stdin);
			std::cout << std::endl;
      		std::cin.clear();
		}
		if (!input.empty()) {
			newContact.setNickname(input);
			break ;
		}
	}

	while (true) {
		std::cout << "Your phone number: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
      		std::clearerr(stdin);
			std::cout << std::endl;
      		std::cin.clear();
		}
		if (!input.empty()) {
			newContact.setPhonenumber(input);
			break ;
		}
	}
	
	while (true) {
		std::cout << "Your darkest secret: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
      		std::clearerr(stdin);
			std::cout << std::endl;
      		std::cin.clear();
		}
		if (!input.empty()) {
			newContact.setSecret(input);
			break ;
		}
	}

	contacts[index % 8] = newContact;
	index++;
}

std::string PrintTen(std::string str) {
	if (str.length() > 9)
		return (str.substr(0, 9) + '.');
	else
		return (str);
}

int	PhoneBook::DisplayContents() {

	if (PhoneBook::index == 0) {
		std::cout << "Phonebook is empty" << std::endl;
		return (1);
	}
	std::cout << std::left << std::setw(10) << "index" << '|'
							<< std::setw(10) << "first name" << '|'
							<< std::setw(10) << "last name" << '|'
							<< std::setw(10) << "nick name" << std::endl;
	for (int index = 0; index < PhoneBook::index; index++)
	{
		Contact contact = PhoneBook::contacts[index];
		std::cout << std::left << std::setw(10) << index << '|'
							<< std::setw(10) << PrintTen(contact.getFirstname()) << '|'
							<< std::setw(10) << PrintTen(contact.getLastname())	 << '|'
							<< std::setw(10) << PrintTen(contact.getNickname())	<< std::endl;
		if (index == 7)
			break ;
	}
	return (0);
}

int GetIndex(int index_phonebook) {
	int index_n;

	while (true) {
		std::string index;

		std::cout << "Put index : ";
		std::getline(std::cin, index);
		if (std::cin.eof()) {
			std::clearerr(stdin);
			std::cout << std::endl;
			std::cin.clear();
		}
		if (index.length() > 1) {
			std::cout << "Index error: too long" << std::endl;
			continue ;
		}
		if (index[0] < '0' || index[0] > '8')
		{
			std::cout << "Index error: out of range" << std::endl;
			continue ;
		}
		index_n = index[0] - '0';
		if (index_n > index_phonebook - 1)
		{
			std::cout << "Index error: out of range" << std::endl;
			continue ;
		}
		break ;
	}
	return (index_n);
}

void PhoneBook::SearchContact() {
	
	if (DisplayContents())
		return ;
	
	int index_n = GetIndex(PhoneBook::index);

	Contact contact;
	contact = PhoneBook::contacts[index_n];

	std::cout << std::left << std::setw(12) << "first name" << ": " << contact.getFirstname() << std::endl;
	std::cout << std::left << std::setw(12) << "last name" << ": " << contact.getLastname() << std::endl;
	std::cout << std::left << std::setw(12) << "nick name" << ": " << contact.getNickname() << std::endl;
	std::cout << std::left << std::setw(12) << "number" << ": " << contact.getPhonenumber() << std::endl;
	std::cout << std::left << std::setw(12) << "secret" << ": " << contact.getSecret() << std::endl;
}
