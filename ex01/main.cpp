#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Büro1(151, "BigBig");
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
		Bureaucrat Büro2(0, "SmallSmall");
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
		Bureaucrat Büro3(67, "Correct");
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
	
	return 0;
}