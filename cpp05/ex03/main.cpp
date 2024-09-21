#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

// void leak()
// {
//     system("leaks Bureaucrat");
// }

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        std::cout << "\x1b[32mBureaucrat Tests:\x1b[0m" << std::endl;
        Bureaucrat b1("Alice", 42);
        std::cout << b1.getName() << ", bureaucrat grade " << b1.getGrade() << std::endl;
        b1.incrementGrade();
        std::cout << b1.getName() << ", bureaucrat grade " << b1.getGrade() << std::endl;
        b1.decrementGrade();
        std::cout << b1.getName() << ", bureaucrat grade " << b1.getGrade() << std::endl;
        
        Bureaucrat b2("Bob", 150);
        std::cout << b2.getName() << ", bureaucrat grade " << b2.getGrade() << std::endl;
        b2.decrementGrade(); // This should throw an exception
    }
    catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n\x1b[34mForm Execution Tests:\x1b[0m" << std::endl;
        Bureaucrat bur("Charlie", 1);
        ShrubberyCreationForm shrubForm("home");
        shrubForm.beSigned(bur);
        shrubForm.execute(bur);

        PresidentialPardonForm pardonForm("Zaphod");
        pardonForm.beSigned(bur);
        pardonForm.execute(bur);

        RobotomyRequestForm roboForm("Bender");
        roboForm.beSigned(bur);
        roboForm.execute(bur);
    }
    catch (std::exception &e) {
        std::cerr << "Caught an exception during form execution: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n\x1b[36mIntern Tests:\x1b[0m" << std::endl;
        Intern intern;
        AForm* form1 = intern.makeForm("robotomy request", "Bender");
        Bureaucrat internBur(2);
        form1->beSigned(internBur);
        form1->execute(internBur);
        delete form1; // Clean up

        AForm* form2 = intern.makeForm("presidential pardon", "Zaphod");
        form2->beSigned(internBur);
        form2->execute(internBur);
        delete form2; // Clean up
    }
    catch (const std::exception &e) {
        std::cerr << "Caught an exception during intern operation: " << e.what() << std::endl;
    }

    return 0;
}
