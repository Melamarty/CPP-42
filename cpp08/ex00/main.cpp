#include "easyfind.hpp"

int main()
{
    std::vector<int> myVec;
    myVec.push_back(5);
    myVec.push_back(3);
    myVec.push_back(6);

    try {
        std::vector<int>::iterator it = easyfind(myVec, 5);
        std::cout << "Value found: " << *it << std::endl;

        it = easyfind(myVec, 6);
        std::cout << "Value found: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}