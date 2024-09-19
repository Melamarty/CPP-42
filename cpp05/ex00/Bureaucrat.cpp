#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Default constructor called" << std::endl;
	this->grade = 100;
}

Bureaucrat::Bureaucrat(int grade)
{
	try
	{
		if (grade > 0 && grade < 150)
		{
			this->grade = grade;
			std::cout << "Constructor called" << std::endl;
		}
		else
			throw (grade);
	} catch  (int g){
		if (g < 0)
			this->GradeTooLowException();
		else
			this->GradeTooHighException();
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called" << std::endl;
}

void Bureaucrat::GradeTooHighException() {
	std::cout << "Grade is too high" << std::endl;
}

void Bureaucrat::GradeTooLowException() {
	std::cout << "Grade is too low" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	try {
		this->grade--;
		if (this->grade < 0)
			throw (0);
		else if (this->grade)
			throw(1);
	} catch (int type){
		if (type)
			this->GradeTooHighException();
		else
			this->GradeTooLowException();
	}
}

void Bureaucrat::decrementGrade()
{
	try {
		this->grade++;
		if (this->grade < 0)
			throw (0);
		else if (this->grade)
			throw(1);
	} catch (int type){
		if (type)
			this->GradeTooHighException();
		else
			this->GradeTooLowException();
	}
}