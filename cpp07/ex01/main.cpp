#include "iter.hpp"

int main()
{
    std::string arr[] = {"Hello", "World", "C++", "Templates"};
    int len = sizeof(arr) / sizeof(arr[0]);

    iter(arr, len, f<std::string>);

    return 0;
}
