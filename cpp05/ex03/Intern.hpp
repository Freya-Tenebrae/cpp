/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 00:09:56 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/15 02:11:10 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
# define Intern_HPP

# include <string>
# include <iostream>

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		/* ****************************************************************** */
		/* CONSTRUCTOR & DESTRUCTOR                                           */
		/* ****************************************************************** */
		Intern();
		Intern(const Intern &b);
		~Intern();

		/* ****************************************************************** */
		/* MEMBER FUNCTION                                                    */
		/* ****************************************************************** */
		AForm	*makePresidentialPardonForm(const std::string target);
		AForm	*makeRobotomyRequestForm(const std::string target);
		AForm	*makeShrubberyCreationForm(const std::string target);
		AForm	*makeForm(const std::string formName, const std::string target);

		/* ****************************************************************** */
		/* OPERATOR OVERLOADING                                               */
		/* ****************************************************************** */
		Intern	&operator=(const Intern &f);

		/* ****************************************************************** */
		/* MISCELLANEOUS                                                      */
		/* ****************************************************************** */
		class FormDidntExistException : std::exception
		{
			public:
				virtual const char* what() const throw();
		};//!GradeTooHighException
};//!Intern
/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */

typedef struct	s_forms
{
	std::string	formName;
	AForm	*(Intern::*makeForms)(const std::string target);
}				t_forms;

#endif