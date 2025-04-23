#include "ScalarConverter.hpp"

void printConversions(double d)
{
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible\n";
	else if (!isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d) << "'\n";

	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d) << "f\n";
	std::cout << "double: " << d << "\n";
}

void ScalarConverter::convert(const std::string& input)
{
	// gestione input uguale a nanf, nan, -inf, +inf, +inff, -inff
	if (input == "nanf" || input == "+inff" || input == "-inff")
	{
		float f = std::strtof(input.c_str(), NULL);
		std::cout << "char: impossible\nint: impossible\n";
		std::cout << "float: " << input << "\n";
		std::cout << "double: " << static_cast<double>(f) << "\n";
		return ;
	}
	else if (input == "nan" || input == "+inf" || input == "-inf")
	{
		double d = std::strtod(input.c_str(), NULL);
		std::cout << "char: impossible\nint: impossible\n";
		std::cout << "float: " << static_cast<float>(d) << "f\n";
		std::cout << "double: " << input << "\n";
		return ;
	}
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		char c = input[0];
		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(c) << "f\n";
		std::cout << "double: " << static_cast<double>(c) << "\n";
		return ;
	}
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
	{
		char c = input[1];
		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
		std::cout << "double: " << static_cast<double>(c) << "\n";
		return ;
	}
	if (!input.empty() && input[input.length() - 1] == 'f')
	{
		char* end;
		float f = std::strtof(input.c_str(), &end);
		if (*end != 'f' || *(end + 1) != '\0')
		{
			std::cout << "Invalid float input\n";
			return ;
		}
		printConversions(static_cast<double>(f));
		return ;
	}
	char* end;
	double d = std::strtod(input.c_str(), &end);
	if (*end != '\0')
	{
		std::cout << "Invalid double/int input\n";
		return ;
	}
	printConversions(d);
}

/**
void ScalarConverter::convert(const std::string& input)
{
	std::istringstream iss(input);
	const char *err[4];
	int			i_val = 0;
	size_t		isnan = 0;
	float		f_val = 0;
	double		d_val = 0;
	char		c_val;

	if (iss >> f_val)
		;
	else
		err[2] = "nanf";
	if (iss >> d_val)
		;
	else
		err[3] = "nan";
	if (input.find_first_not_of("0123456789abcdef.-") != std::string::npos || input.compare("nan") == 0)
	{
		isnan = 1;
		err[0] = "impossible";
		err[1] = "impossible";
		err[2] = "nanf";
		err[3] = "nan";
		std::cout << "char: " << err[0] << std::endl;
		std::cout << "int: " << err[1] << std::endl;
		std::cout << "float: " << err[2] << std::endl;
		std::cout << "double: " << err[3] << std::endl;
		
	}
	else
	{
		i_val = std::atoi(input.c_str());
		c_val = (char)i_val;
		f_val = std::atof(input.c_str());
		d_val = (double)std::atof(input.c_str());
		if (c_val < 32 || c_val > 126)
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: '" << c_val << '\'' << std::endl;
		std::cout << "int: " << i_val << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f_val << "f" << std::endl;
		std::cout << "double: " << d_val << std::endl;
	}
}
 */
// Canonical form
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) {(void)copy;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {(void)copy; return *this;}
ScalarConverter::~ScalarConverter() {}
