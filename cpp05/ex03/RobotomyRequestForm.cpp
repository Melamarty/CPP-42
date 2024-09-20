#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("form", 72, 45)
{
	std::cout << "Default constructor callled" << std::endl;
	target = "default";
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("form", 72, 45),  target(target)
{
	std::cout << "Constructor callled" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &p) :AForm("form", 72, 45),  target(p.target)
{
	std::cout << "Copy Constructor callled" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &p)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &p)
	{
		this->target = p.target;
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget()
{
	return target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called" << std::endl;
}

void RobotomyRequestForm::execute( Bureaucrat const & b) const
{
    if (b.getGrade() > this->get_sign_grade())
        throw AForm::GradeTooLowException();
    std::srand(std::time(NULL));
    if (std::rand() % 2)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy on " << this->target << " has failed!" << std::endl;
}