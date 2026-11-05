#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : name("nameless"), status_signed(false), required_grade_for_signing(1), required_grade_for_executing(1)
{
}

AForm::AForm(std::string name) : name(name.empty() ? "nameless" : name), status_signed(false), required_grade_for_signing(1), required_grade_for_executing(1)
{
}

AForm::AForm(std::string name, size_t required_grade_for_signing, size_t required_grade_for_executing)
	: name(name.empty() ? "nameless" : name),
	  status_signed(false),
	  required_grade_for_signing(!required_grade_for_signing ? throw GradeTooHighException() : required_grade_for_signing > 150 ? throw GradeTooLowException() : required_grade_for_signing),
	  required_grade_for_executing(!required_grade_for_executing ? throw GradeTooHighException() : required_grade_for_executing > 150 ? throw GradeTooLowException() : required_grade_for_executing)
{
}

AForm::AForm(AForm &src) : name(src.name), status_signed(src.status_signed), required_grade_for_signing(src.required_grade_for_signing), required_grade_for_executing(src.required_grade_for_executing)
{
}

std::string	AForm::getName(void) const
{
	return this->name;
}

size_t	AForm::getRequired_grade_for_signing(void) const
{
	return this->required_grade_for_signing;
}

size_t	AForm::getRequired_grade_for_executing(void) const
{
	return this->required_grade_for_executing;
}

void	AForm::beSigned(Bureaucrat &target)
{
	// if (target.getGrade() < this->required_grade_for_signing)
	// 	throw GradeTooHighException();
	if (target.getGrade() > this->required_grade_for_signing)
		throw GradeTooLowException();
	else
		this->status_signed = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high:";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low:";
}

std::ostream	&operator<<(std::ostream &os, const AForm &obj)
{
	os << "form: " << obj.getName()  << ", the required grade for signing is: "
		<< obj.getRequired_grade_for_signing() << " and for executing: " << obj.getRequired_grade_for_executing();
	return os;
}

// bool	AForm::is_signed() const
// {
// 	return this->status_signed;
// }



void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->status_signed && executor.getGrade() > this->required_grade_for_executing)
		throw GradeTooLowException();
	else
		execution();
}
