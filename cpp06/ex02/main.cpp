#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

char ABC() {
    const char chars[] = {'A', 'B', 'C'};
    
    std::srand(std::time(NULL));
    int i = std::rand() % 3;
    return (chars[i]);
}

Base * generate(void)
{
    char c = ABC();
    if (c == 'A')
        return new A;
    else if (c == 'B')
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "PTR to : A\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "PTR to : B\n";
    else if (dynamic_cast<C *>(p))
        std::cout << "PTR to : C\n";
    else
        std::cout << "UNKNOWN PTR\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "PTR to : A\n";
    } catch(std::bad_cast &)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "PTR to : B\n";
        } catch(std::bad_cast &)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "PTR to : C\n";
            } catch(std::bad_cast &)
            {
                std::cout << "UNKNOWN PTR\n";
            }
        }
    }
}

int main ()
{
    Base *b = generate();
    identify(b);
    identify(*b);
}