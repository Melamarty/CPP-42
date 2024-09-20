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
        RobotomyRequestForm robotomy("robot");
        PresidentialPardonForm pardon("Bob");

        alice.executeForm(shrubbery); // Should fail because the form is not signed
        shrubbery.beSigned(alice);    // Alice signs the form
        alice.executeForm(shrubbery); // Now it works

        robotomy.beSigned(alice);     // Sign the robotomy form
        alice.executeForm(robotomy);  // Execute robotomy form

        // Pardon form requires higher grade to sign and execute, will throw exception if Alice tries
        alice.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}