#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	public:
		std::string	target;
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		void	execution() const;
		// ShrubberyCreationForm(const std::string name, const size_t grade_for_signing, const size_t grade_for_executing);
		// ShrubberyCreationForm(const std::string target, const std::string name, const size_t grade_for_signing, const size_t grade_for_executing);
		// ShrubberyCreationForm(const AForm &other);
		// ShrubberyCreationForm(const ShrubberyCreationForm &other);
		// ShrubberyCreationForm	&operator=(const AForm &other);
		
};

#endif