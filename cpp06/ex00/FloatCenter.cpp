
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cctype>

float stringToFloat( const std::string& str ) {
    
	float result = 0.0f;
    float decimal = 0.1f;
    bool isNegative = false;
    bool hasDecimal = false;

    size_t i = 0;

    // Handle leading whitespace
    while (i < str.size() && std::isspace(str[i])) {
        i++;
    }

    // Handle optional sign
    if (i < str.size() && (str[i] == '+' || str[i] == '-')) {
        isNegative = (str[i] == '-');
        i++;
    }

    // Convert integral part
    while (i < str.size() && std::isdigit(str[i])) {
        result = result * 10.0f + static_cast<float>(str[i] - '0');
        i++;
    }

    // Convert fractional part
    if (i < str.size() && str[i] == '.') {
        hasDecimal = true;
        i++;

        while (i < str.size() && std::isdigit(str[i])) {
            result = result + (static_cast<float>(str[i] - '0') * decimal);
            decimal *= 0.1f;
            i++;
        }
    }

    // Handle exponent (if any)

    // Handle trailing whitespace

    if (isNegative) {
        result = -result;
    }

    return result;
}
