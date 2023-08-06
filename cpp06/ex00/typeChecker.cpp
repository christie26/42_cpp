
#include "ScalarConverter.hpp"

// one character, printable 
bool isChar ( std::string str ) {
	if (str.length() == 1)
		if (std::isprint(str[0]))
			return true;
	return false;
}

// -2147483648 ~ 2147483647 - I don't care
bool isInt( const std::string& str ) {
	size_t start = 0;
	if (str[0] == '-' || str[0] == '+') {
        start = 1;
    }
    for (size_t i = start; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool isFloat( const std::string& str ) {
	size_t start = 0;
	if (str[0] == '-' || str[0] == '+') {
        start = 1;
    }
    for (size_t i = start; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool isDouble( const std::string& str ) {
	size_t start = 0;
	if (str[0] == '-' || str[0] == '+') {
        start = 1;
    }
    for (size_t i = start; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int ScalarConverter::getType( std::string str ) {
	if (isChar(str))
		return CHAR;
	else if (isInt(str))
		return INT;
	else if (isFloat(str))
		return FLOAT;
	else if (isDouble(str))
		return DOUBLE;
	return 5;
}
