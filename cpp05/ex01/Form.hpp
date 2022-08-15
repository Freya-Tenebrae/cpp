/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:31:13 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/14 22:01:13 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToBeSigned;
		const int			_gradeToBeExecuted;
	public:
		/* ****************************************************************** */
		/* CONSTRUCTOR & DESTRUCTOR                                           */
		/* ****************************************************************** */
		Form(std::string name, int gradeToBeSigned, int gradeToBeExecuted);
		Form(const Form &f);
		~Form();

		/* ****************************************************************** */
		/* GETTER & SETTER                                                    */
		/* ****************************************************************** */
		std::string	getName(void) const;
		int			getGradeToBeSigned(void) const;
		int			getGradeToBeExecuted(void) const;
		bool		getIsSigned(void) const;

		/* ****************************************************************** */
		/* MEMBER FUNCTION                                                    */
		/* ****************************************************************** */
		void		beSigned(const Bureaucrat &b);

		/* ****************************************************************** */
		/* OPERATOR OVERLOADING                                               */
		/* ****************************************************************** */
		Form		&operator=(const Form &f);
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
		class AlreadySignedException : std::exception
		{
			public:
				virtual const char* what() const throw();
		};//!AlreadySignedException
};//!Form
/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */
std::ostream	&operator<<(std::ostream &output, const Form &f);

#endif