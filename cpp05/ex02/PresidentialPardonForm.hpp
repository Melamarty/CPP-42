#pragma once

#include "Bureaucrat.hpp"
class PresidentialPardonForm : public Bureaucrat
{
	private:
		int grade;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &);
		PresidentialPardonForm &operator = (const PresidentialPardonForm &);
		~PresidentialPardonForm();
};