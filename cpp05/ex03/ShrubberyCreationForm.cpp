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
    if (b.getGrade() > this->getExec_grade()) {
        throw AForm::GradeTooLowException();
    }

	std::ofstream file((this->target + "_shrubbery").c_str());
    if (file.is_open()) {
        std::cout << "ASCII tree created successfully!" << std::endl;
        file << MY_ASCII_ART;
		std::cout << "\n\x1b[34mASCII TREE:\x1b[0m\n" << std::endl;
		std::cout << "\033[32m" << MY_ASCII_ART << "\033[0m" << std::endl;
		std::cout << "\n" << std::endl;
        file.close();
    } else {
        std::cerr << "Error: Could not open file for writing." << std::endl;
    }
}

