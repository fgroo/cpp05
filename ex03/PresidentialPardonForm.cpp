#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("presidential", 25, 5), target("none") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential", 25, 5), target(target) {}

void	PresidentialPardonForm::execution() const
{
	std::cout << this->target << " has been pardoned by Zaphid Beeblebrox" << std::endl;
}