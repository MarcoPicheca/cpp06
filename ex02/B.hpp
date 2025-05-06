#ifndef B_HPP
#define B_HPP
#include <iostream>
#include "Base.hpp"

class B : public Base
{
	private:
		std::string _name;
	public:
		B(/* args */);
		~B();	
		void setName(std::string& name);
		std::string getName() const;
};

#endif