#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat {
	private:
		const std::string name;
		int	   grade;
	public:
		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat &operator =(const Bureaucrat &);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw();
		};
		void signForm(AForm &form);
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b);
#endif