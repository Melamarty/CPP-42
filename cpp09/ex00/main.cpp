#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: bad argument\n";
        return 0;
    }
    (void)av;
    BitcoinExchange be;
    try
    {
        be.readData("data.csv");
        be.readInput(av[1]);
        // be.displayInput();
        // be.displayData();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
}