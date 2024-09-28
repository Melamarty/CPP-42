#include "converters.hpp"

int is_digit(const std::string &s)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
            return (0);
    }
    return 1;
}

int displayble(char c)
{
    return (c >= 32 && c <= 126);
}

void display_nan(float f)
{
    std::cout << "int    : impossible" << std::endl;
    std::cout << "char   : impossible" << std::endl;
    std::cout << "float  : " << f  << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(f) << std::endl;
}

void char_converter(const std::string &s)
{
    int c = static_cast<int>(s[1]);
    if (!displayble(c))
        std::cout << "char   : Non Displayable\n";
    else
        std::cout << "char   : " << "'" << s[1] << "'\n";
    std::cout << "int    : " << static_cast<int>(c) << std::endl ;
    std::cout << "float  : " << static_cast<float>(c) << "f" <<  std::endl ;
    std::cout << "double : " << static_cast<double>(c) << std::endl ;
}


void int_converter(const std::string &s)
{
    // std::cout << "Is INT\n";
    double d = strtod(s.c_str(), NULL);
    if (d > 255 || d < 0)
        std::cout << "char   : Overflow\n";
    else if (!displayble(d))
        std::cout << "char   : Non Displayable\n";
    else
        std::cout << "char   : " << "'" << static_cast<char>(d) << "'\n";
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int    : Overflow\n";
    else
        std::cout << "int    : " << static_cast<int>(d) << std::endl ;
    std::cout << "float  : " << static_cast<float>(d) << "f" <<  std::endl ;
    std::cout << "double : " << static_cast<double>(d) << std::endl ;
}

void float_converter(const std::string &s)
{
    double d = strtof(s.c_str(), NULL);

    if (s == "nanf")
    {
        display_nan(d);
        return ;
    }
    if (d > 255 || d < 0)
        std::cout << "char   : Overflow\n";
    else if (!displayble(d))
        std::cout << "char   : Non Displayable\n";
    else
        std::cout << "char   : " << "'" << static_cast<char>(d) << "'\n";
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int    : Overflow\n";
    else
        std::cout << "int    : " << static_cast<int>(d) << std::endl ;
    std::cout << "float  : " << static_cast<float>(d) << "f" <<  std::endl ;
    std::cout << "double : " << static_cast<double>(d) << std::endl ;
}

void double_converter(const std::string &s)
{
    double d = strtod(s.c_str(), NULL);

    if (s == "nan")
    {
        display_nan(d);
        return ;
    }
    if (d > 255 || d < 0)
        std::cout << "char   : Overflow\n";
    else if (!displayble(d))
        std::cout << "char   : Non Displayable\n";
    else
        std::cout << "char   : " << "'" << static_cast<char>(d) << "'\n";
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int    : Overflow\n";
    else
        std::cout << "int    : " << static_cast<int>(d) << std::endl ;
    std::cout << "float  : " << static_cast<float>(d) << "f" <<  std::endl ;
    std::cout << "double : " << static_cast<double>(d) << std::endl ;
}