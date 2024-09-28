#include "ScalarConverter.hpp"


int main (int ac, char **av)
{
    if (ac != 2)
        return (std::cout << "Error\n", 0);
    ScalarConverter::convert(av[1]);
}