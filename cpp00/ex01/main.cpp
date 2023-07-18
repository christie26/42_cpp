
#include <iostream>

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
  PhoneBook myPhonebook;
  std::string input;

  std::cout << "Enter your command: ";
  std::getline(std::cin, input);
  std::cout << "You put " << input << std::endl;

  // myContact.setFirstname("Thoma");
  // std::cout << myContact.getFirstname() << std::endl;
  return 0;
}
