#include "Data.hpp"

Data::Data(const std::string& name) : _name(name)
{}

Data::Data(const Data& copy)
{
	_name = copy._name;
}

Data& Data::operator=(const Data& copy)
{
	if (this != &copy)
		_name = copy._name;
	return *this;
}

Data::Data(){}

Data::~Data(){}

std::string Data::getName()
{
	return _name;
}
