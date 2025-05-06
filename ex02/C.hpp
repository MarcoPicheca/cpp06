#ifndef C_HPP
#define C_HPP
#include <iostream>
#include "Base.hpp"

class C : public Base
{
	private:
		std::string _name;
	public:
		C(/* args */);
		~C();
		void setName(std::string& name);
		std::string getName() const;
};

#endif