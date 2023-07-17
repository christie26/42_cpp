
#include "Contact.hpp"
#include <iostream>

int main() {
  Contact myContact;

  myContact.setFirstname("Thoma");
  std::cout << myContact.getFirstname() << std::endl;
  return 0;
}