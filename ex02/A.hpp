#ifndef A_HPP
#define A_HPP
#include <iostream>
#include "Base.hpp"

class A : public Base
{
	private:
		std::string _name;
	public:
		A(/* args */);
		~A();
		void setName(std::string& name);
		std::string getName() const;
};

#endif