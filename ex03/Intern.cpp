#include "Intern.hpp"
#include <cstddef>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern(void) {}

typedef AForm	*(*FormFactory)(const std::string &target);

static AForm	*createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &form_name, const std::string &target) const
{
	static const std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	static const FormFactory	factories[3] = {&createShrubbery, &createRobotomy, &createPardon};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == names[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return (factories[i](target));
		}
	}
	std::cerr << "Intern: form \"" << form_name << "\" does not exist" << std::endl;
	return NULL;
}
