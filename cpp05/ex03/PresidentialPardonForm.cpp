#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("pform", 25, 5)
{
	std::cout << "Default constructor callled" << std::endl;
	target = "default";
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) :AForm("pform", 25, 5),  target(target)
{
	std::cout << "Constructor callled" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : AForm("pform", 25, 5), target(p.target)
{
	std::cout << "Copy Constructor callled" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &p)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &p)
	{
		this->target = p.target;
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget()
{
	return target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called" << std::endl;
}

void PresidentialPardonForm::execute( Bureaucrat const & b) const
{
    if (b.getGrade() > this->getSign_grade())
        throw AForm::GradeTooLowException();
    std::cout << this->target <<" has been pardoned by Zaphod Beeblebrox" << std::endl;
}