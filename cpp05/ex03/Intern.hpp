#pragma once

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        static AForm* x(std::string const &);
        static AForm* y(std::string const &);
        static AForm* z(std::string const &);
    public:
        Intern();
        Intern(const Intern &);
        Intern &operator =(const Intern &);
        AForm *makeForm(std::string const &, std::string const &);
        ~Intern();
};