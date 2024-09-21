#include "Bureaucrat.hpp"
#include <iostream>

// void leak()
// {
//     system("leaks Bureaucrat");
// }
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    {
        try {
            std::cout << "\n\x1b[34mfirst Test:\x1b[0m" << std::endl;
            Bureaucrat alice("Alice", 42);
            std::cout << alice.getName() << ", bureaucrat grade " << alice.getGrade() << std::endl;

            alice.incrementGrade();
            std::cout << alice.getName() << ", bureaucrat grade " << alice.getGrade() << std::endl;

            alice.decrementGrade();
            std::cout << alice.getName() << ", bureaucrat grade " << alice.getGrade() << std::endl;

            Bureaucrat bob;
            std::cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << std::endl;

            bob.incrementGrade();
            std::cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << std::endl;

            bob.decrementGrade();
            bob.decrementGrade();
            std::cout << bob.getName() << " after exception, bureaucrat grade " << bob.getGrade() << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException &e) {
            std::cerr << "Caught an exception: " << e.what() << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException &e) {
            std::cerr << "Caught an exception: " << e.what() << std::endl;
        }

        try {
            std::cout << "\n\x1b[34msecond Test:\x1b[0m" << std::endl;
            Bureaucrat charlie("Charlie", 1);
            std::cout << charlie.getName() << ", bureaucrat grade " << charlie.getGrade() << std::endl;

            charlie.incrementGrade();
            std::cout << charlie;
        }
        catch (const Bureaucrat::GradeTooHighException &e) {
            std::cerr << "Caught an exception: " << e.what() << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException &e) {
            std::cerr << "Caught an exception: " << e.what() << std::endl;
        }
    }

    {
        try {
            std::cout << "\n\x1b[34mthird Test:\x1b[0m" << std::endl;
            Form formA("Form A", 50, 75);
            std::cout << formA << std::endl;

            Bureaucrat alice("Alice", 42);
            std::cout << alice << std::endl;

            alice.signForm(formA);
            std::cout << formA << std::endl;

            Bureaucrat bob("Bob", 60);
            std::cout << bob << std::endl;
            bob.signForm(formA);
            std::cout << formA << std::endl;
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try {
            Form invalidForm("def", 151, 152);
        }
        catch (const Form::GradeTooLowException &e) {
            std::cout << e.what() << std::endl;
        }
        catch (const Form::GradeTooHighException &e) {
            std::cout << e.what() << std::endl;
        }

        try {
            Form anotherInvalidForm("HIGHT", 0, -1);
        }
        catch (const Form::GradeTooLowException &e) {
            std::cout << e.what() << std::endl;
        }
        catch (const Form::GradeTooHighException &e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}
