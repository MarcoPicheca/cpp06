#include "Serializer.hpp"


Serializer& Serializer::operator=(const Serializer& copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr)
{
	std::string nameFile;
	nameFile = ptr->getName();
	std::ofstream file("file_1", std::ios::binary);
	if (!file.is_open()) {
		std::cerr
			<< "Error: Failed to open file for writing."
			<< std::endl;
		return static_cast<uintptr_t>(1);
	}
	file.write(reinterpret_cast<const char*>(ptr),
			   sizeof(*ptr));
	file.close();
	std::cout << "Object serialized successfully." << std::endl;
	return static_cast<uintptr_t>(0);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* obj = NULL;
	std::ifstream file("file_1", std::ios::binary);
	if (!file.is_open())
	{
		std::cerr
			<< "Error: Failed to open file for reading."
			<< std::endl;
		return NULL;
	}
	file.read(reinterpret_cast<char*>(&raw),
			  sizeof(obj));
	file.close();
	std::cout << "Object deserialized successfully." << std::endl;
	return obj;
}
