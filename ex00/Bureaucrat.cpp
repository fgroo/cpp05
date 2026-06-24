#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(size_t grade, std::string name)
{
	if (grade > 150)
		throw GradeTooHighException();
	else if (!grade)
		throw GradeTooLowException();
	this->grade = grade;
	if (name.empty())
		this->name = "nameless";
	else
		this->name = name;
}

void	Bureaucrat::getGrade(const Bureaucrat &target)
{
	std::cout << this->name << std::endl;
}
void	Bureaucrat::getName(const Bureaucrat &target)
{
	std::cout << this->name << std::endl;
}
Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}
Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
}


std::ostream	Bureaucrat::&operator<<(std::ostream os, const Bureaucrat &obj)
{
	os << this->name << "bureaucrat grade " << this->grade << std::endl;
	return (os);
}