#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private :
		const std::string name;
		bool	_signed;
		const int sign_grade;
		const int exec_grade;
	public:
		Form();
		Form(std::string name,int sg, int eg);
		~Form();
		Form(const Form &f);
		Form &operator =(const Form &);
		int get_sign_grade() const;
		int get_exec_grade() const;
		std::string get_name() const;
		bool get_signed() const;
		class GradeTooHighException:public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException:public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		void beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &outpuy, const Form &form);
#endif