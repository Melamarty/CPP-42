#include "Span.hpp"

Span::Span(): maxSize(0)
{
    std::cout << "default constructor called\n";
}
Span::Span(int n) : maxSize(n)
{
    std::cout << "A new Span created wih size: " << n << std::endl;
}

Span::~Span()
{
    std::cout << "Span Destroyed\n";
}

Span::Span (const Span &sp)
{
    std::cout << "A new Span copied wih size: " << sp.maxSize << std::endl;
    if (this != &sp)
    {
        this->nbs = sp.nbs;
    }
}

Span &Span::operator= (const Span &sp)
{
    std::cout << "A new Span assigned wih size: " << sp.maxSize << std::endl;
    Span *s = new Span(sp.maxSize);
    if (this != &sp)
    {
        s->nbs = sp.nbs;
        return *s;
    }
    return (*this);
}

void Span::addNumber(int nb)
{
    if (nbs.size() >= maxSize)
        throw (std::runtime_error("\x1B[31mwe can't add new element: the Span is Full\033[0m"));
    nbs.push_back(nb);
    std::cout << "✅ element "<< nb <<" Added to Span\n";
}

void Span::display()
{
    int nbsSize = nbs.size();
    if (!maxSize || !nbsSize)
        std::cout << "the Span is empty\n";
    else
    {
        std::cout << "\x1B[32mYour current Span :\n\x1B[37m";
        for (int i = 0; i < nbsSize; i++)
        {
            std::cout << "[";
            std::cout << nbs[i];
            std::cout << "] ";
        }
        std::cout << std::endl;
    }
}

void Span::shortestSpan()
{
    std::cout << "\x1B[32mLooking for shortest span ...\x1B[37m\n";
    if (nbs.size() < 2)
        throw(std::runtime_error("\x1B[31mcannot find the shortest span\033[0m"));
    std::vector <int> tmp = nbs;
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];
    for (size_t i = 2; i < maxSize; i++)
    {
        if (tmp[i] - tmp[i-1] < shortest)
            shortest = tmp[i] - tmp[i - 1];
    }
    std::cout << "Shotest Span found : " << shortest << std::endl;
}

void Span::longestSpan()
{
    std::cout << "\x1B[32mLooking for longest span ...\x1B[37m\n";
    if (nbs.size() < 2)
        throw(std::runtime_error("\x1B[31mcannot find the longest span\033[0m"));
    int min = *std::min_element(nbs.begin(), nbs.end());
    int max = *std::max_element(nbs.begin(), nbs.end());
    // std::cout << "min :" << min << std::endl;
    // std::cout << "max :" << max << std::endl;
    std::cout << "Longest Span found : " << max - min << std::endl;
}