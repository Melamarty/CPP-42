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

std::string AForm::getName() const
{
	return name;
}

int AForm::getSign_grade() const
{
	return sign_grade;
}
int AForm::getExec_grade() const
{
	return exec_grade;
}

bool AForm::getSigned() const
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
	output << AForm.getName() << "signed : " << AForm.getSigned()
			<< "sign grade: " << AForm.getSign_grade()
			<< "execution grade" << AForm.getSign_grade();
	return (output) ;
}

AForm::AForm(const AForm &b) : name(b.name), _signed(b.getSigned()),sign_grade(b.getSign_grade()),exec_grade(b.getExec_grade())
{
    std::cout << "AForm : " << this->name << " copy Constructor 	is called." << std::endl;
}

AForm& AForm::operator=(const AForm &b)
{
    std::cout << "AForm : " << this->name << " constructor  assignment called." << std::endl;
    if (this != &b)
        this->_signed = b.getSigned();
    return *this;
}