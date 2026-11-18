#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		~Intern(void);
		AForm	*makeForm(const std::string &form_name, const std::string &target) const;
};

#endif
