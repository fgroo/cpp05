#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Büro(151, "Büro");
		std::cout << Büro << std::endl;
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