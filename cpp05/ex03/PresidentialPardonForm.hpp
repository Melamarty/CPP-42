#pragma once

#include "Bureaucrat.hpp"
class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string );
		PresidentialPardonForm(const PresidentialPardonForm &);
		PresidentialPardonForm &operator = (const PresidentialPardonForm &);
		~PresidentialPardonForm();
		std::string getTarget();
		void execute( Bureaucrat const & ) const;
};