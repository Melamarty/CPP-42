#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

// void leak()
// {
//     system("leaks Bureaucrat");
// }

int main() {
    try {
        Bureaucrat alice("Alice", 50);
        ShrubberyCreationForm shrubbery("garden");
        shrubbery.execute(alice);
        RobotomyRequestForm robotomy("robot");
        PresidentialPardonForm pardon("Bob");
        alice.executeForm(shrubbery);
        shrubbery.beSigned(alice);    
        alice.executeForm(shrubbery); 
        robotomy.beSigned(alice);
        alice.executeForm(robotomy);  

        alice.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}