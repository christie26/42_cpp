
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {

private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string secret;

public:
	void setFirstname(std::string first_name);
	void setLastname(std::string last_name);
	void setNickname(std::string nick_name);
	void setPhonenumber(std::string phone_number);
	void setSecret(std::string secret);

	std::string	getFirstname();
	std::string	getLastname();
	std::string	getNickname();
	std::string	getPhonenumber();
	std::string	getSecret();
};

#endif
