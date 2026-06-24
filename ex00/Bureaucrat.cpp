#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(size_t grade)
{
	if (grade > 150)
		throw GradeTooHighException();
	else if (!grade)
		throw GradeTooLowException();
	this->grade = grade;
}

void	Bureaucrat::getGrade(const Bureaucrat &target)
{
	std::cout << this->name << std::endl;
}
void	Bureaucrat::getName(const Bureaucrat &target)
{
	std::cout << this->name << std::endl;
}



std::ostream	Bureaucrat::&operator<<(std::ostream os, const Bureaucrat &obj)
{
	os << this->name << "bureaucrat grade " << this->grade << std::endl;
	return (os);
}