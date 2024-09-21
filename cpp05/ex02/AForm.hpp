#ifndef AAForm_HPP
#define AAForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
	private :
		const std::string name;
		bool	_signed;
		const int sign_grade;
		const int exec_grade;
	public:
		AForm();
		AForm(std::string name,int sg, int eg);
		~AForm();
		AForm(const AForm &f);
		AForm &operator =(const AForm &);
		int getSign_grade() const;
		int getExec_grade() const;
		std::string getName() const;
		bool getSigned() const;
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
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &outpuy, const AForm &AForm);
#endif