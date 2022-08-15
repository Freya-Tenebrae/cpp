/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/15 18:20:50 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		/* ****************************************************************** */
		/* CONSTRUCTOR & DESTRUCTOR                                           */
		/* ****************************************************************** */
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &b);
		~Bureaucrat();

		/* ****************************************************************** */
		/* GETTER & SETTER                                                    */
		/* ****************************************************************** */
		std::string	getName(void) const;
		int			getGrade(void) const;

		/* ****************************************************************** */
		/* MEMBER FUNCTION                                                    */
		/* ****************************************************************** */
		void		Promoted();
		void		Demoted();
		void		signForm(AForm &f);
		void		executeForm(AForm const &f);

		/* ****************************************************************** */
		/* OPERATOR OVERLOADING                                               */
		/* ****************************************************************** */
		Bureaucrat	&operator=(const Bureaucrat &f);
		/* ****************************************************************** */
		/* MISCELLANEOUS                                                      */
		/* ****************************************************************** */
		class GradeTooHighException : std::exception
		{
			public:
				virtual const char* what() const throw();
		};//!GradeTooHighException

		class GradeTooLowException : std::exception
		{
			public:
				virtual const char* what() const throw();
		};//!GradeTooLowException
};//!Bureaucrat
/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */
std::ostream	&operator<<(std::ostream &output, const Bureaucrat &b);

#endif