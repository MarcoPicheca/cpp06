#include "ScalarConverter.hpp"
#include <cstdlib> // per atof, atoi, ecc.
#include <cctype>  // per isprint
#include <cmath>  // per isprint

void ScalarConverter::convert(const std::string& input)
{
    std::istringstream iss(input);
    char c_value;
    int i_value;
    float f_value;
    double d_value;
    int isnan = 0;

    iss >> c_value;
    iss >> i_value;
    iss >> f_value;
    iss >> d_value;
    
    if (input.find_last_not_of("0987654321abcdef.") != std::string::npos
        && input.length() < 2 && input.length() > 0)
    {
        isnan = 1;
    }
    // CHAR
    std::cout << "char: ";
    if (c_value < 0 || std::isnan(c_value) || isnan)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(c_value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << '\'' << static_cast<char>(c_value) << '\'' << std::endl;

    // INT
    std::cout << "int: ";
    if (i_value < std::numeric_limits<int>::min() || i_value > std::numeric_limits<int>::max() || std::isnan(i_value) || isnan)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(i_value) << std::endl;

    // FLOAT
    std::cout << "float: ";
    if (isnan)
        std::cout << "nanf\n";
    else if (f_value - static_cast<int>(f_value) == 0 && !isnan)
        std::cout << static_cast<float>(f_value) << ".0f" << std::endl;
    else
        std::cout << static_cast<float>(f_value) << "f" << std::endl;

    // DOUBLE
    std::cout << "double: ";
    if (isnan)
        std::cout << "nan\n";
    else if (d_value - static_cast<int>(d_value) == 0)
        std::cout << static_cast<double>(d_value) << ".0" << std::endl;
    else
        std::cout << static_cast<double>(d_value) << std::endl;
}

// Canonical form
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) {(void)copy;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {(void)copy; return *this;}
ScalarConverter::~ScalarConverter() {}
