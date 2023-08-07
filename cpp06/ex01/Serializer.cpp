
#include "Serializer.hpp"

Serializer::Serializer () {
	std::cout << "Default constructor called" << std::endl;
}

Serializer::~Serializer () {
	std::cout << "Default destructor called" << std::endl;
}

Serializer::Serializer ( const Serializer& ) {
	std::cout << "Copy constructor called" << std::endl;
}

Serializer& Serializer::operator= ( const Serializer& ) {
	std::cout << "Copy assignment operator called" << std::endl;
	std::cout << "StaticClass copy assignment is not supported." << std::endl;
	return *this;
}

uintptr_t Serializer::serialize( Data* ptr ) {

	uintptr_t value = reinterpret_cast<uintptr_t>(ptr);
	return value;
}

Data* Serializer::deserialize( uintptr_t raw ) {

	Data* value = reinterpret_cast<Data*>(raw);
	return value;
}
