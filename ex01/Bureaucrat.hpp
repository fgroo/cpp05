#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name);
		Bureaucrat(const size_t grade);
		Bureaucrat(const std::string name, const size_t grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);
		size_t		getGrade(void) const;
		std::string	getName(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);
		void		signForm(Form &form);

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
		size_t				grade;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj);

#endif