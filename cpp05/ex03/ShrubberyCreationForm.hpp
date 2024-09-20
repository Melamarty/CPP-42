#pragma once

#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string );
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &);
		~ShrubberyCreationForm();
		std::string getTarget();
		void execute(Bureaucrat const &b) const;
};