#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{

	public:
		Form(void);
		Form(std::string name);
		Form(std::string name, size_t grade);
		Form(Form &other);
		void	beSigned(Bureaucrat &target);

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
		const std::string	name;
		bool				is_signed;
		const size_t		grade;
		const size_t		required_grade_for_signing;
		const size_t		required_grade_for_executing;
};

std::ostream	&operator<<(std::ostream &os, const Form &obj);

#endif
