#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>

class Data
{
	private:
		std::string _name;
	public:
		Data();
		Data(const std::string& name);
		Data(const Data& copy);
		Data& operator=(const Data& copy);
		~Data();
		std::string getName();
};

#endif