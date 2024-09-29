#include "Span.hpp"

void randomSpan (Span &sp, int size)
{
    std::srand(std::time(NULL));
    for (int i = 0; i < size; i++)
    {
        int r = std::rand() % 10000;
        sp.addNumber(r);
    }
}

int main  ()
{
    Span sp(10);

    sp.display();
    try
    {
        randomSpan(sp, 10);
    } catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    sp.display();
    try
    {
        sp.shortestSpan();
        sp.longestSpan();
    } catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}