#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string name;
		int	   grade;
	public:
		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		void GradeTooHighException();
		void GradeTooLowException();
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class grade_exeph : public std::exception{
			public:
				const char* what() const throw();
		};
		class grade_exepl : public std::exception{
			public:
				const char* what() const throw();
		};
};

#endif