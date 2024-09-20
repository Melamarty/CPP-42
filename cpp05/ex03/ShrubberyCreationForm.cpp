#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("sform", 145, 137)
{
	std::cout << "Default constructor callled" << std::endl;
	target = "default";
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("sform", 145, 137),  target(target)
{
	std::cout << "Constructor callled" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &p) : AForm("sform", 145, 137),  target(p.target)
{
	std::cout << "Copy Constructor callled" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &p)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &p)
	{
		this->target = p.target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget()
{
	return target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &b) const {
    if (b.getGrade() > this->get_exec_grade()) {
        throw AForm::GradeTooLowException();
    }

	std::ofstream file((this->target + "_shrubbery").c_str());
    if (file.is_open()) {
        file << "hhhhhhhh";
        std::cout << "ASCII tree created successfully!" << std::endl;
        file.close();
    } else {
        std::cerr << "Error: Could not open file for writing." << std::endl;
    }
}
