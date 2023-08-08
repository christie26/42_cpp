
#include "ScalarConverter.hpp"
#include <sstream>
#include <cctype>

int stringToInt( const std::string& str ) {
    int result;
    std::istringstream iss(str);
    
    if (!(iss >> result)) {
        throw false;
    }
    char remaining;
    if (!(iss >> remaining)) {
        return result;
    }
    throw false;
}

char stringToChar ( const std::string& str ) {
	if (str.length() != 1)
        throw (false);
	if (!std::isprint(str[0]))
        throw (false);
	return str[0];
}

float stringToFloat( const std::string& str ) {
    size_t idx = 0;
    bool negative = false;
    bool decimalFound = false;
    float result = 0.0f;
    int decimalPlace = 1;

    if (str[idx] == '-' || str[idx] == '+') {
        negative = (str[idx] == '-');
        idx++;
    }

    while (idx < str.size()) {
        char c = str[idx];

        if (std::isdigit(c)) {
            if (!decimalFound)
                result = result * 10.0f + static_cast<float>(c - '0');
            else {
                result += static_cast<float>(c - '0') / (10.0f * decimalPlace);
                decimalPlace *= 10;
            }
        } 
        else if (c == '.' && !decimalFound)         
            decimalFound = true;
        else if (c == 'f' && idx + 1 == str.size())
            break ;
        else
            throw false;
        idx++;
    }
    if (str[idx] != 'f')
        throw false;
    if (negative)
        result = -result;

    return result;
}

double stringToDouble( const std::string& str ) {
    size_t idx = 0;
    bool negative = false;
    bool decimalFound = false;
    double result = 0.0f;
    int decimalPlace = 1;

    if (str[idx] == '-' || str[idx] == '+') {
        negative = (str[idx] == '-');
        idx++;
    }

    while (idx < str.size()) {
        char c = str[idx];

        if (std::isdigit(c)) {
            if (!decimalFound)
                result = result * 10.0f + static_cast<double>(c - '0');
            else {
                result += static_cast<double>(c - '0') / (10.0f * decimalPlace);
                decimalPlace *= 10;
            }
        } 
        else if (c == '.' && !decimalFound)         
            decimalFound = true;
        else
            throw false;
        idx++;
    }

    if (negative)
        result = -result;

    return result;
    
}

int ScalarConverter::handlePseudo( const std::string& str ) {

	int type = UNKNOWN;

	if (str == "inff" || str == "+inff" || str == "-inff" || str == "nanf") {
		type = FLOAT;
		if (str == "-inff")
			_floatValue = -std::numeric_limits<float>::infinity();
		if (str == "+inff" || str == "inff")
			_floatValue = std::numeric_limits<float>::infinity();
		if (str == "nanf")
			_floatValue = std::numeric_limits<float>::quiet_NaN();
	}

	if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan") {
		type = DOUBLE;
		if (str == "-inf")
			_doubleValue = -std::numeric_limits<double>::infinity();
		if (str == "+inf" || str == "inf")
			_doubleValue = std::numeric_limits<double>::infinity();
		if (str == "nan")
			_doubleValue = std::numeric_limits<double>::quiet_NaN();
	}
	return type;
}

int ScalarConverter::typeDetector( const std::string& str ) {

	int type = handlePseudo(str);
	if (type != UNKNOWN)
        return type;

    try {
        _intValue = stringToInt(str);
        return INT;
    } catch (bool isInt) {  }
    
    try {
        _charValue = stringToChar(str);
        return CHAR;
    } catch (bool isChar) { }

    try {
        _floatValue = stringToFloat(str);
        return FLOAT;
    } catch (bool isFloat) { }

    try {
        _doubleValue = stringToDouble(str);
        return DOUBLE;
    } catch (bool isDouble) {  }

    return UNKNOWN;
}


