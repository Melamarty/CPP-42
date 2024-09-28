#include "Templates.hpp"

template <typename T>
T max(T a, T b)
{
    if (a <= b)
        return (b);
    return a;
}

int main ()
{
    int a = 1,b= 2;
    std::cout << "Before Swap\n";
    std::cout << "value of a: " << a << std::endl;
    std::cout <<"value of b: " << b << std::endl;

    Swap(a, b);
    std::cout << "After Swap\n";
    std::cout << "value of a: " << a << std::endl;
    std::cout <<"value of b: " << b << std::endl;

    std::cout << "max and min Tests\n";
    std::cout << min(1, 2) << std::endl;
    std::cout << min('a', 'a') << std::endl;
    std::cout << max("a", "b") << std::endl;
    std::cout << max('a', 'a') << std::endl;

    return (0);
}