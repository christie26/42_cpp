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
