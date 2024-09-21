#include "Form.hpp"

Form::Form () : name("default"),_signed(false), sign_grade(150), exec_grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Form::Form (std::string name, int sg, int eg) : name (name),  _signed(false),  sign_grade(sg) , exec_grade(eg)
{
	if (sg < 1)
		throw GradeTooHighException();
	if (sg > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw(){
	//std::cout << "Grade is too high" << std::endl;
	return "Grade is too high" ;
}

const char* Form::GradeTooLowException::what() const throw(){
	//std::cout << "Grade is too low" << std::endl;
	return "Grade is too low" ;
}

std::string Form::get_name() const
{
	return name;
}

int Form::get_sign_grade() const
{
	return sign_grade;
}
int Form::get_exec_grade() const
{
	return exec_grade;
}

bool Form::get_signed() const
{
	return _signed;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > sign_grade) //?
		throw GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &output, const Form &form)
{
	output << form.get_name() << "signed : " << form.get_signed()
			<< "sign grade: " << form.get_sign_grade()
			<< "execution grade" << form.get_sign_grade();
	return (output) ;
}

Form::Form(const Form &b) : name(b.name), _signed(0),sign_grade(b.get_sign_grade()),exec_grade(b.get_exec_grade())
{
    std::cout << "Form : " << this->name << " copy Constructor 	is called." << std::endl;
}

Form& Form::operator=(const Form &b)
{
    std::cout << "Form : " << this->name << " constructor  assignment called." << std::endl;
    if (this != &b)
        this->_signed = b.get_signed();
    return *this;
}