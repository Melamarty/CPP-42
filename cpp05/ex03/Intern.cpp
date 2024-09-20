#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default constructor called" << std::endl;
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
	std::string forms[] = {
            "shrubbery creation",
            "robotomy request",
            "presidential pardon"

        };
        
        AForm* (*formCreators[])(std::string const &) = {
            &createShrubberyForm,
            &createRobotomyForm,
            &createPresidentialForm
        };
        
        for (int i = 0; i < 3; i++) {
            if (name == forms[i]) {
                std::cout << "Intern creates " << name << std::endl;
                return formCreators[i](target);
            }
        }
        std::cerr << "Error: Form name \"" << name << "\" does not exist." << std::endl;
        return (NULL);

}

AForm* Intern::createShrubberyForm(std::string const & target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(std::string const & target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(std::string const & target)
{
    return new PresidentialPardonForm(target);
}


Intern::~Intern()
{
	std::cout << "Destructor called" << std::endl;
}