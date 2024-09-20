
#pragma once
#include "Bureaucrat.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string );
		RobotomyRequestForm(const RobotomyRequestForm &);
		RobotomyRequestForm &operator = (const RobotomyRequestForm &);
		~RobotomyRequestForm();
		std::string getTarget();
		void execute( Bureaucrat const & b) const;
};
