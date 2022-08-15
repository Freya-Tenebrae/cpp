/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:31:13 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/15 18:24:09 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
		AForm();
		AForm(std::string name, int gradeToBeSigned, int gradeToBeExecuted);
		AForm(const AForm &f);
		virtual ~AForm();

		/* ****************************************************************** */
		/* GETTER & SETTER                                                    */
		/* ****************************************************************** */
		std::string		getName(void) const;
		int				getGradeToBeSigned(void) const;
		int				getGradeToBeExecuted(void) const;
		bool			getIsSigned(void) const;

		/* ****************************************************************** */
		/* MEMBER FUNCTION                                                    */
		/* ****************************************************************** */
		void			beSigned(const Bureaucrat &b);
		virtual void	execute(const Bureaucrat &executor) const = 0;

		/* ****************************************************************** */
		/* OPERATOR OVERLOADING                                               */
		/* ****************************************************************** */
		AForm			&operator=(const AForm &f);
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
		
		class NotSignedExeption : std::exception
		{
			public:
				virtual const char* what() const throw();
		};//!NotSignedExeption
};//!AForm
/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */
std::ostream	&operator<<(std::ostream &output, const AForm &f);

#endif