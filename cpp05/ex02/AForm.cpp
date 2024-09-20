#include "AForm.hpp"

AForm::AForm () : name("default"), sign_grade(150), exec_grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm (std::string name, int sg, int eg) : name (name),  _signed(false),  sign_grade(sg) , exec_grade(eg)
{
	if (sg < 1)
		throw GradeTooHighException();
	if (sg > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw(){
	//std::cout << "Grade is too high" << std::endl;
	return "Grade is too high" ;
}

const char* AForm::GradeTooLowException::what() const throw(){
	//std::cout << "Grade is too low" << std::endl;
	return "Grade is too low" ;
}

std::string AForm::get_name() const
{
	return name;
}

int AForm::get_sign_grade() const
{
	return sign_grade;
}
int AForm::get_exec_grade() const
{
	return exec_grade;
}

bool AForm::get_signed() const
{
	return _signed;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() < sign_grade)
		_signed = true;
	else
		GradeTooLowException();
}

std::ostream &operator<<(std::ostream &output, const AForm &AForm)
{
	output << AForm.get_name() << "signed : " << AForm.get_signed()
			<< "sign grade: " << AForm.get_sign_grade()
			<< "execution grade" << AForm.get_sign_grade();
	return (output) ;
}

AForm::AForm(const AForm &b) : name(b.name), _signed(b.get_signed()),sign_grade(b.get_sign_grade()),exec_grade(b.get_exec_grade())
{
    std::cout << "AForm : " << this->name << " copy Constructor 	is called." << std::endl;
}

AForm& AForm::operator=(const AForm &b)
{
    std::cout << "AForm : " << this->name << " constructor  assignment called." << std::endl;
    if (this != &b)
        this->_signed = b.get_signed();
    return *this;
}