#pragma once

#include <iostream>

#include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
    public:
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;
        MutantStack()
        {
            std::cout << "MutantStack created\n";
        };
        MutantStack(const MutantStack &ms)
        {
            this = std::stack<T>(ms);
            std::cout << "MutantStack copied\n";
        };
        MutantStack &operator=(const MutantStack &ms)
        {
            std::stack<T>::operator=(ms);
            std::cout << "MutantStack assigned\n";
            return *this;
        };
        ~MutantStack()
        {
            std::cout << "MutantStack destroyed\n";
        };
        iterator begin()
        {
            return std::stack<T>::c.begin();
        }
        iterator end()
        {
            return std::stack<T>::c.end();
        }
        const_iterator begin() const
        {
            return std::stack<T>::c.begin();
        }
        const_iterator end() const
        {
            return std::stack<T>::c.end();
        }
};