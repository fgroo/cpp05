#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP


# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void) : AForm("shrubbery", 145, 137) {}
		void	AForm::beSigned(Bureaucrat &target) {
			if (target.grade )
		}

};

#endif