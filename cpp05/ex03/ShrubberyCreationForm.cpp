/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:20:16 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/15 18:26:44 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
									AForm("ShrubberyCreationForm", 145, 137),
									_target("nothing")
{

	std::cout << "\033[0;35mA ShrubberyCreationForm targetting nothing";
	std::cout << " is created\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
									AForm("ShrubberyCreationForm", 145, 137),
									_target(target)
{

	std::cout << "\033[0;35mA ShrubberyCreationForm targetting " << _target;
	std::cout << " is created\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &f):
		AForm(f.getName(), f.getGradeToBeSigned(), f.getGradeToBeExecuted()),
		_target(f.getTarget())
{
	*this = f;
	std::cout << "\033[0;35mA ShrubberyCreationForm targetting " << _target;
	std::cout << " is cloned\033[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[0;35mA ShrubberyCreationForm targetting " << _target;
	std::cout << " is destroyed\033[0m" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
} 

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::string newFilename;

	if (getIsSigned() == false)
		throw AForm::NotSignedExeption();
	else if (executor.getGrade() > getGradeToBeExecuted())
		throw AForm::GradeTooLowException();
	else
	{
		newFilename = getTarget();
		newFilename.append("_shrubbery");

		std::ofstream	ofs(const_cast<char*>(newFilename.c_str()), \
														std::ofstream::out);
		if (ofs.is_open())
		{
			ofs << "               ,@@@@@@@," << std::endl;
			ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
			ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
			ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
			ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
			ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
			ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
			ofs << "       |o|        | |         | |" << std::endl;
			ofs << "       |.|        | |         | |" << std::endl;
			ofs << "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
			ofs.close();
		}
		else
			std::cout << newFilename << " can't be created or opened..." << std::endl;
	}
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const \
													ShrubberyCreationForm &f)
{
	(void)f;
	return (*this);
}
