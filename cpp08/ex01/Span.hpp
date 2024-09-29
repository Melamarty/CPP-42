#pragma once

#include <iostream>

#include <vector>
#include <ctime>

class Span
{
    private:
        unsigned int maxSize;
        std::vector <int>  nbs;
        Span();
    public:
        Span(int n);
        ~Span();
        Span (const Span &sp);
        Span &operator= (const Span &sp);
        void addNumber(int nb);
        void display();
        void shortestSpan();
        void longestSpan();
};
