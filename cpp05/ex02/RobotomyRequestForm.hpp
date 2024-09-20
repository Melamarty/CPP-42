
#pragma once
#include "Bureaucrat.hpp"
class RobotomyRequestForm : public Bureaucrat
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &);
		RobotomyRequestForm &operator = (const RobotomyRequestForm &);
		~RobotomyRequestForm();
};

