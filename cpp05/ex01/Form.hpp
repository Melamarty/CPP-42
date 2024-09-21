#pragma once

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
		Form(std::string ,int, int);
		~Form();
		Form(const Form &);
		Form &operator =(const Form &);
		int get_sign_grade(void) const;
		int get_exec_grade(void) const;
		std::string get_name() const;
		bool get_signed() const;
		class GradeTooHighException:public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException:public std::exception
		{
			public:
				const char *what() const throw();
		};
		void beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &outpuy, const Form &form);
