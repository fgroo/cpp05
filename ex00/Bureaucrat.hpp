#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	public:
		Bureaucrat(const size_t grade)
		~Bureaucrat(void)
		GradeTooHighException(void)
		GradeTooLowException(void)
		void	getGrade(const Bureaucrat &target)
		void	getName(const Bureaucrat &target)

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		Bureaucrat(void) {}
		const std::string	name;
		size_t				grade
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj);

#endif