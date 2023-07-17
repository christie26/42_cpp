<<<<<<< HEAD

#include "Contact.hpp"
#include <iostream>

int main() {
  Contact myContact;

  myContact.setFirstname("Thoma");
  std::cout << myContact.getFirstname() << std::endl;
  return 0;
}
=======
#include <iostream>

int main(int argc, char **argv) 
{
	if (argc != 2)
		std::cout << "Put only one input";
	else
		for (int i = 1; i < argc; i++)
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
	std::cout << std::endl;
	return (0);
}
>>>>>>> 97ddabb449f67ffe17291195315ec8d013ec51f9
