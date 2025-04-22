#include "ScalarConverter.hpp"


int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Wrong number of args\n";
		return 0;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}