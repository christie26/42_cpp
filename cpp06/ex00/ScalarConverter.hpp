
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {

private:

	ScalarConverter ( void );
	~ScalarConverter( void );
	ScalarConverter (const ScalarConverter &scalar);
	ScalarConverter& operator= (const ScalarConverter& scalar);

public:
	enum Type {
        CHAR,
        INT,
        FLOAT,
		DOUBLE
    };
	void convert ( std::string str );
};

#endif
