#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter Created" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter Destoryed" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &s)
{
    (void)s;
   std::cout << "CC for ScalarConverter called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &s)
{
    (void)s;
   std::cout << "CAO for ScalarConverter called" << std::endl;
   return *this;
}

void ScalarConverter::convert(const std::string &s)
{
    // std::cout << isChar(s) << " " << isInt(s) << " " << isFloat(s) << " " << isDouble(s) << std::endl;
    if (s.empty())
        std::cout << "EMPTY STRING\n";
    else if (isChar(s))
        char_converter(s);
    else if (isInt(s))
        int_converter(s);
    else if (isFloat(s))
        float_converter(s);
    else if (isDouble(s))
        double_converter(s);
    else
        std::cout << "UNKNOWN TYPE\n";
}