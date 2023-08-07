
#include "Serializer.hpp"

int main ( void ) {

	Data myData = { 42, 42.42, "fortytwo" };

	uintptr_t intValue = Serializer::serialize(&myData);
	Data* deserializedData = Serializer::deserialize(intValue);

	std::cout << "Original data: " 
		<< myData.intValue << ", " 
		<< myData.doubleValue << ", "
		<< myData.stringValue << std::endl;
	
	std::cout << "Deserialized data: " 
		<< deserializedData->intValue << ", " 
		<< deserializedData->doubleValue << ", "
		<< deserializedData->stringValue << std::endl;

}
