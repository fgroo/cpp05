#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	try
	{
		Bureaucrat Büro1("BigBig", 151);
		std::cout << Büro1 << std::endl;

		//-----------//
		std::cout << Büro1 << std::endl;
		Büro1.incrementGrade();
		std::cout << Büro1 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "unexpected: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Büro2("SmallSmall", 0);
		std::cout << Büro2 << std::endl;

		//-----------//
		std::cout << Büro2 << std::endl;
		Büro2.decrementGrade();
		std::cout << Büro2 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "unexpected: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Büro3("Correct", 67);
		std::cout << Büro3 << std::endl;

		//-----------//
		std::cout << Büro3 << std::endl;
		Büro3.incrementGrade();
		Büro3.incrementGrade();
		std::cout << Büro3 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "unexpected: " << e.what() << std::endl;
	}

	std::cout << "next part: the form" << std::endl;

	try
	{
		Bureaucrat	super("amazing", 30);
		ShrubberyCreationForm	form;
		form.beSigned(super);
		form.execute(super);
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "unexpected: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	super("amazing", 30);
		RobotomyRequestForm	form;
		form.beSigned(super);
		form.execute(super);
		form.execute(super);
		form.execute(super);
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "unexpected: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	super("amazing", 30);
		PresidentialPardonForm	form;
		form.beSigned(super);
		form.execute(super);
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "unexpected: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	super("amazing", 1);
		PresidentialPardonForm	form("SUPREME LEADER");
		form.beSigned(super);
		form.execute(super);
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "unexpected: " << e.what() << std::endl;
	}

	return 0;
}
