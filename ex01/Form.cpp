#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : name("nameless"), grade(150), is_signed(false), required_grade_for_signing(1), required_grade_for_executing(1)
{
}

Form::Form(std::string name) : name(name.empty() ? "nameless" : name), grade(150), is_signed(false), required_grade_for_signing(1), required_grade_for_executing(1)
{
}
Form::Form(size_t grade) : name("nameless"),
							grade(!grade ? throw GradeTooHighException() : grade > 150 ? throw GradeTooLowException() : grade),
							is_signed(false), required_grade_for_signing(1), required_grade_for_executing(1) 
{
}

Form::Form(std::string name, size_t grade) : name(name.empty() ? "nameless" : name),
												grade(!grade ? throw GradeTooHighException() : grade > 150 ? throw GradeTooLowException() : grade),
												is_signed(false), required_grade_for_signing(1), required_grade_for_executing(1)		
{
}

Form::Form(Form &src) : name(src.name), grade(src.grade), is_signed(src.is_signed), required_grade_for_signing(src.required_grade_for_signing), required_grade_for_executing(src.required_grade_for_executing)
{
}

std::string	Form::getName(void) const
{
	return this->name;
}

size_t	Form::getGrade(void) const
{
	return this->grade;
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
	if (target.getGrade() < this->required_grade_for_signing)
		throw GradeTooHighException();
	else if (target.getGrade() > this->required_grade_for_signing)
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
	os << "form: " << obj.getName()  << ", has grade: " << obj.getGrade() << ", the required grade for signing is: "
		<< obj.getRequired_grade_for_signing() << "and for executing: " << obj.getRequired_grade_for_executing();
	return os;
}