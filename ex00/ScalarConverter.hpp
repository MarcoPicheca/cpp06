#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <climits>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
		~ScalarConverter();
	public:
		static void	convert(const std::string& toBeConvert);
};
	
void printConversions(double d);

#endif