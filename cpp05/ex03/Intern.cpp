#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default constructor called" << std::endl;
}

AForm* Intern::x(std::string const & target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::y(std::string const & target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::z(std::string const & target)
{
    return new PresidentialPardonForm(target);
}

Intern::Intern(const Intern &i)
{
	std::cout << "copy constructor called" << std::endl;
	*this = i;
}

Intern &Intern::operator=(const Intern &i)
{
	std::cout << "copy assignment operator called" << std::endl;
	(void)i;
	return *this;
}

AForm *Intern::makeForm(std::string const& name, std::string const &target)
{
	std::string table[] = {
            "shrubbery creation",
            "robotomy request",
            "presidential pardon"

        };
        
        AForm* (*pointerToFun[])(std::string const &) =
        {
            &x,
            &y,
            &z
        };
        
        for (int i = 0; i < 3; i++)
        {
            if (name == table[i])
            {
                std::cout << "Intern creates " << name << std::endl;
                return (pointerToFun[i](target));
            }
        }
        std::cerr << "Error: Form name \"" << name << "\" does not exist." << std::endl;
        return (NULL);

}



Intern::~Intern()
{
	std::cout << "Destructor called" << std::endl;
}