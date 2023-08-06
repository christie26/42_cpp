
#include "ScalarConverter.hpp"


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

char stringToChar ( const std::string& str ) {
	if (str.length() != 1)
        throw (false);
	if (!std::isprint(str[0]))
        throw (false);
	return str[0];
}

bool isChar ( const std::string& str ) {

	if (str.length() == 1)
		if (std::isprint(str[0]))
			return true;
	return false;
}

int ScalarConverter::getType( std::string str ) {

    try {
        _charValue = stringToChar(str);
        std::cout << "char value: " << _charValue << std::endl;
        return CHAR;
    }
    catch (bool isChar) {
        std::cout << "it's not char" << std::endl;
    }
    return INT;
	// if (isChar(str))
	// 	return CHAR;
	// else if (isInt(str))
	// 	return INT;
	// else if (isFloat(str))
	// 	return FLOAT;
	// else if (isDouble(str))
	// 	return DOUBLE;
	// return 5;
}


