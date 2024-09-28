#include "converters.hpp"

bool isChar(const std::string &s)
{
    if (s.length() != 3)
        return (0);
    if (s[0] != '\'' || s[2] != '\'')
        return (0);
    return (1);
}

bool isInt(const std::string &s)
{
    char *end = NULL;

    std::strtol(s.c_str(), &end, 10);
    std::string res = end;
    return (res.empty());
}

bool isFloat(const std::string &s)
{
    if (s == "nanf" || s == "-inff" || s == "+inff")
        return true;

    char *end = NULL;

    if (s == "inff")
        return (false);
    if (s.length() <= 1)
        return (false);
    std::strtof(s.c_str(), &end);
    std::string res = end;
    if (res.length() != 1 || res[0] != 'f')
        return (false);
    return true;
}

bool isDouble(const std::string &s)
{
    if (s == "nan" || s == "-inf" || s == "+inf")
        return true;
    if (s == "inf")
        return (false);
    char *end = NULL;
    std::strtod(s.c_str(), &end);
    
    std::string res = end;
    return (res.empty());
}
