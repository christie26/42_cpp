<<<<<<< HEAD

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
	std::string first_name;
	std::string last_name;

	public:
// Setter
	void setFirstname(std::string first_name);
// Getter
	std::string	getFirstname();
};

#endif
=======
#include <iostream>

class Contact {
	private:
		char	*first_name;
		char	*last_name;
		char	*nickname;
		int		phone_number;
		char	*darkest_secret;
	
	public:
		void setFirstname(char *first_name);
		void setLastname(char *last_name);
		void setNickname(char *nickname);
		void setFirstname(int phone_numer);
		void setSecret(char *darkest_secret);

		char *getFirstname();
		char *getLastname();
		char *getNickname();
		char *getFirstname();
		char *getSecret();
};
>>>>>>> 97ddabb449f67ffe17291195315ec8d013ec51f9
