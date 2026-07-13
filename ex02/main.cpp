#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	

	std::cout << "next part: the form" << std::endl;

	Bureaucrat	toolow("too low", 130);
	Form		form("for the students", 30, 10);
	toolow.signForm(form);

	Bureaucrat	toolow2("too high", 5);
	toolow2.signForm(form);

	return 0;
}