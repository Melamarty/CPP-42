#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : name("default")
{
	if (grade > 150)
		throw grade_exepl();
	if (grade < 1)
		throw grade_exeph();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw grade_exepl();
	if (grade < 1)
		throw grade_exeph();
	this->grade = grade;
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
	if (this->grade - 1 < 1)
		throw grade_exeph();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw grade_exepl();
	this->grade++;
}

const char *Bureaucrat::grade_exeph::what() const throw()
{
	return ("high grade");
}
const char *Bureaucrat::grade_exepl::what() const throw()
{
	return ("low grade");
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