#include "Bureaucrat.hpp"

// void leak()
// {
//     system("leaks Bureaucrat");
// }

int main() {
    // atexit(leak);
    try 
    {
        {
            Bureaucrat b2("Alice", 42);
            std::cout << b2.getName() << ", bureaucrat grade " << b2.getGrade() << std::endl;
            b2.incrementGrade();
            std::cout << b2.getName() << ", bureaucrat grade " << b2.getGrade() << std::endl;
            b2.decrementGrade();
            std::cout << b2.getName() << ", bureaucrat grade " << b2.getGrade() << std::endl;
        }
        {
            Bureaucrat b1;
            std::cout << b1.getName() << ", bureaucrat grade " << b1.getGrade() << std::endl;
            b1.incrementGrade();
            std::cout << b1.getName() << ", bureaucrat grade " << b1.getGrade() << std::endl;
            b1.decrementGrade();
            b1.decrementGrade();
            std::cout << b1.getName() << "after exception" << ", bureaucrat grade " << b1.getGrade() << std::endl;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

     try {
         std::cout << "\n\n================================================================================\n" << std::endl;
         Bureaucrat b4("Charlie", 1);
         std::cout << b4.getName() << ", bureaucrat grade " << b4.getGrade() << std::endl;
         std::cout << b4;
         b4.incrementGrade();
     }
     catch (const std::exception &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    return (0);
}