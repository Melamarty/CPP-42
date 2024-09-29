#pragma once

#include <iostream>
#include <iterator>
#include <vector>


template <typename T>

typename T::iterator easyfind(T& cnt, int val)
{
    typename T::iterator it = std::find(cnt.begin(), cnt.end(), val);
    
    if (it == cnt.end())
        throw std::runtime_error("The value not found");
    return it;
}