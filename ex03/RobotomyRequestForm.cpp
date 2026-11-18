#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), target("none") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), target(target) {}

void	RobotomyRequestForm::execution() const
{
	static	int fifthy = 1; // question: does it has to be random?

	if (fifthy)
		std::cout << this->target << " has been robotomized successfully!" << std::endl, fifthy = 0;
	else
	 	std::cout << this->target << " BRUH, FAILED, robotomize next time!" << std::endl, fifthy = 1;
}