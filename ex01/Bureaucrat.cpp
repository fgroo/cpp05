#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("nameless"), grade(150)
{
}

Bureaucrat::Bureaucrat(size_t grade, std::string name) : name(name.empty() ? "nameless" : name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		this->grade = rhs.grade;
	}
	return *this;
}


Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->name << " has been destroyed" << std::endl;
}

size_t	Bureaucrat::getGrade() const
{
	return this->grade;
}
std::string	Bureaucrat::getName() const
{
	return this->name;
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}
void	Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

