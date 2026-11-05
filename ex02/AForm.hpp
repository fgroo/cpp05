#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{

	public:
		AForm(void);
		AForm(std::string name);
		AForm(std::string name, size_t required_grade_for_signing, size_t required_grade_for_executing);
		AForm(AForm &src);
		std::string	getName(void) const;
		// size_t	getGrade(void) const;
		size_t	getRequired_grade_for_signing(void) const;
		size_t	getRequired_grade_for_executing(void) const;

		void	beSigned(Bureaucrat &target);
		// bool	is_signed() const;

		void	execute(Bureaucrat const &executor) const; // TODO:
		virtual void	execution() const = 0;

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
		bool				status_signed;
		const size_t		required_grade_for_signing;
		const size_t		required_grade_for_executing;
};

std::ostream	&operator<<(std::ostream &os, const AForm &obj);

#endif
