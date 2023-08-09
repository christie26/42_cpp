
#include "easyfind.hpp"

const char* ValueNotFoundException::what() const throw () { return "Value not found in container"; }
