
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