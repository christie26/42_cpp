
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

private:
	Contact	phone_book[8];
	int		index;

public:
	PhoneBook();
	void addContact(c);

};

#endif
