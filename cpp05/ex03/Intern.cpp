/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 00:09:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/15 02:24:28 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

Intern::Intern()
{
	std::cout << "\033[0;35mAn Intern is recruited\033[0m" << std::endl;
}

Intern::Intern(const Intern &i)
{
	(void)i;
	std::cout << "\033[0;35mAn Intern is duplicated\033[0m" << std::endl;
}

Intern::~Intern()
{
	std::cout << "\033[0;35mAn Intern is fired\033[0m" << std::endl;
}


/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
AForm	*Intern::makePresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string formName, const std::string target)
{
	t_forms t[] =
	{
		{"presidential pardon", &Intern::makePresidentialPardonForm},
		{"robotomy request", &Intern::makeRobotomyRequestForm},
		{"shrubbery creation", &Intern::makeShrubberyCreationForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (t[i].formName == formName)
			return (this->*t[i].makeForms) (target);
	}
	throw Intern::FormDidntExistException();
}

/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */
Intern	&Intern::operator=(const Intern &i)
{
	(void)i;
	return (*this);
}

/* ************************************************************************** */
/* MISCELLANEOUS                                                              */
/* ************************************************************************** */
const char* Intern::FormDidntExistException::what() const throw()
{
	return ("\033[0;31mForm type didn't exist\033[0m");
}
