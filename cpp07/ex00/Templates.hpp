#pragma once

#include <iostream>

template <typename T>

void Swap(T &a, T &b)
{
    T res;

    res = a;
    a = b;
    b = res;
}

template <typename T>
T min(T a, T b)
{
    if (a >= b)
        return (b);
    return a;
}