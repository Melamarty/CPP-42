#pragma once;

#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Bureaucrat
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &);
		PresidentialPardonForm &operator = (const PresidentialPardonForm &);
		~PresidentialPardonForm();
};