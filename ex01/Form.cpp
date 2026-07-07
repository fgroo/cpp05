#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : name("nameless"), is_signed(false), grade(150), required_grade_for_executing(1), required_grade_for_signing(1)
{
}

Form::Form(std::string name) : name(name.empty() ? "nameless" : name), is_signed(false), grade(150), required_grade_for_executing(1), required_grade_for_signing(1)
{
}
Form::Form(size_t grade) : grade(!grade ? throw()GradeTooHighException : grade > 150 ? throw()GradeTooLowException : grade),
							name("nameless"), is_signed(false), required_grade_for_executing(1), required_grade_for_signing(1) 
{
}

Form::Form(std::string name, size_t grade) : name(name.empty() ? "nameless" : name),
												grade(!grade ? throw()GradeTooHighException : grade > 150 ? throw()GradeTooLowException : grade),
												is_signed(false), required_grade_for_executing(1), required_grade_for_signing(1)		
{
}

Form::Form(Form &other) : this = other;
{
}


Form::beSigned(Bureaucrat &target)
{
	if (target.getGrade < required_grade_for_signing)
		throw GradeTooHighException();
	else if (target.getGrade > required_grade_for_signing)
		throw GradeTooLowException();
	else
		this.is_signed = true;
}

const char*	Form::GradeTooHighException	what() const throw()
{
	return "Grade is too high:";
}

const char*	Form::GradeTooLowException	what() const throw()
{
	return "Grade is too low:";
}

std::ostream	&operator<<(std::ostream &os, const Form &obj)
{
	os << "form: " << obj.name  << ", has grade: " << obj.grade << ", the required grade for signing is: "
		<< obj.required_grade_for_signing <<, "and for executing: " << obj.required_grade_for_executing;
	return os;
}