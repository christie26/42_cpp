
#include "ScalarConverter.cpp"

char stringToChar ( std::string str ) {
	if (str.length() == 1)
		if (std::isprint(str[0]))
			return true;
	return false;
}

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