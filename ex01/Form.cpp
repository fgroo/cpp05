#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : name("nameless"), is_signed(false), required_grade_for_signing(1), required_grade_for_executing(1)
{
}

Form::Form(std::string name) : name(name.empty() ? "nameless" : name), is_signed(false), required_grade_for_signing(1), required_grade_for_executing(1)
{
}

Form::Form(std::string name, size_t required_grade_for_signing, size_t required_grade_for_executing)
	: name(name.empty() ? "nameless" : name),
	  is_signed(false),
	  required_grade_for_signing(!required_grade_for_signing ? throw GradeTooHighException() : required_grade_for_signing > 150 ? throw GradeTooLowException() : required_grade_for_signing),
	  required_grade_for_executing(!required_grade_for_executing ? throw GradeTooHighException() : required_grade_for_executing > 150 ? throw GradeTooLowException() : required_grade_for_executing)
{
}

Form::Form(Form &src) : name(src.name), is_signed(src.is_signed), required_grade_for_signing(src.required_grade_for_signing), required_grade_for_executing(src.required_grade_for_executing)
{
}

std::string	Form::getName(void) const
{
	return this->name;
}

size_t	Form::getRequired_grade_for_signing(void) const
{
	return this->required_grade_for_signing;
}

size_t	Form::getRequired_grade_for_executing(void) const
{
	return this->required_grade_for_executing;
}

void	Form::beSigned(Bureaucrat &target)
{
	// if (target.getGrade() < this->required_grade_for_signing)
	// 	throw GradeTooHighException();
	if (target.getGrade() > this->required_grade_for_signing)
		throw GradeTooLowException();
	else
		this->is_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high:";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low:";
}

std::ostream	&operator<<(std::ostream &os, const Form &obj)
{
	os << "form: " << obj.getName()  << ", the required grade for signing is: "
		<< obj.getRequired_grade_for_signing() << " and for executing: " << obj.getRequired_grade_for_executing();
	return os;
}
