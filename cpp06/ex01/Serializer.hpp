
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>

struct Data {
    int		intValue;
    double	doubleValue;
	std::string stringValue;
};

class Serializer {

public:

	static uintptr_t serialize( Data* ptr );
	static Data* deserialize( uintptr_t raw );

};


#endif
