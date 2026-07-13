#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) : name("nameless"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, size_t grade) : name(name.empty() ? "nameless" : name)
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

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.grade;
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

void Bureaucrat::signForm(Form	&form) // TODO: const after here . understand more should help
{
	try
	{
		form.beSigned(*this);

		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}

}


void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);

		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " failed the execution because: " << e.what() << std::endl;
	}
}


