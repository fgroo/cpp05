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
		Form(std::string name, size_t required_grade_for_signing, size_t required_grade_for_executing);
		Form(Form &src);
		std::string	getName(void) const;
		// size_t	getGrade(void) const;
		size_t	getRequired_grade_for_signing(void) const;
		size_t	getRequired_grade_for_executing(void) const;

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
		// const size_t		grade;
		bool				is_signed;
		const size_t		required_grade_for_signing;
		const size_t		required_grade_for_executing;
};

std::ostream	&operator<<(std::ostream &os, const Form &obj);

#endif
