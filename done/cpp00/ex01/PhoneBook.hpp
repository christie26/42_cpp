
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

private:
	Contact		contacts[8];
	int			index;
	
	int			DisplayContents();

public:
	PhoneBook();

	void		AddContact();
	void		SearchContact();
	std::string getInput();

};

#endif
