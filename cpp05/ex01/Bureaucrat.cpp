#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : name("default")
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called" << std::endl;
}

//char* Bureaucrat::GradeTooHighException() {
//	//std::cout << "Grade is too high" << std::endl;
//	return ("Grade is too high");
//}

//char* Bureaucrat::GradeTooLowException() {
//	//std::cout << "Grade is too low" << std::endl;
//	return ("Grade is too high");
//}

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
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw GradeTooHighException();
	this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("high grade");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("low grade");
}

void Bureaucrat::signForm(Form &form)
{
	if(!form.get_signed())
	{
		std::cout << name << "couldn't sign " << form.get_name() << "because " ;
		throw GradeTooLowException();
	}
	else
		std::cout << name << " signed " << form.get_name() <<std::endl;
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b)
{
	output << b.getName() << "    grade : " << b.getGrade();
	return (output) ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.name), grade(b.grade)
{
    std::cout << "Bureaucrat : " << this->name << " copy Constructor 	is called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bur)
{
    std::cout << "Bureaucrat : " << this->name << " constructor  assignment called." << std::endl;
    if (this != &bur)
        this->grade = bur.grade;
    return *this;
}