#pragma once

#include <iostream>
#include "converters.hpp"

class ScalarConverter
{
    private:
       ScalarConverter(); 
    public:
       ~ScalarConverter(); 
       ScalarConverter(const ScalarConverter &s); 
       ScalarConverter &operator=(const ScalarConverter &s); 
       static void convert(const std::string &s);
};
