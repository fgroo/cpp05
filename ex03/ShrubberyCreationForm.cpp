#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <cstdio>
#include <ostream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shrubbery", 145, 137), target("none") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("shrubbery", 145, 137), target(target) {}

void ShrubberyCreationForm::execution() const // TODO: test write
{
	std::FILE *fd;
	const	std::string target = this->target + "_shrubbery";

	fd = fopen(target.c_str(), "w");
	//size_t rd = std::fwrite(NULL, target.length(), 0 , "w");
	static const std::string tree =
		"    oxoxoo    ooxoo\n"
		"  ooxoxo oo  oxoxooo\n"
		" oooo xxoxoo ooo ooox\n"
		" oxo o oxoxo  xoxxoxo\n"
		"  oxo xooxoooo o ooo\n"
		"    ooo\\o\\  /o/o\n"
		"        \\  \\/ /\n"
		"         |   /\n"
		"         |  |\n"
		"         | D|\n"
		"         |  |\n"
		"         |  |\n"
		" ______/____\\____\n";

	fwrite(tree.c_str(), 1, tree.length(), fd);
	fclose(fd);
}

// ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const size_t grade_for_signing, const size_t grade_for_executing) : AForm(name, grade_for_signing, grade_for_executing), target("student") {} 


// ShrubberyCreationForm::ShrubberyCreationForm(const std::string target, const std::string name, const size_t grade_for_signing, const size_t grade_for_executing) : AForm(name, grade_for_signing, grade_for_executing), target(target) {} 


// ShrubberyCreationForm::ShrubberyCreationForm(const AForm &other) : AForm(other.getName(), other.getRequired_grade_for_signing(), other.getRequired_grade_for_executing()) {}

//ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), other.getRequired_grade_for_signing(), other.getRequired_grade_for_executing()) {}


// ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const AForm &other)
// {
// 	this->name = other.name
// }




// {
// 			if (target.grade )