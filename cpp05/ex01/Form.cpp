/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:31:11 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/15 18:30:09 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

Form::Form():	_name(""),
				_isSigned(false),
				_gradeToBeSigned(75),
				_gradeToBeExecuted(75)
{
	std::cout << "\033[0;35mDefault constructor called. DO NOT USE\033[0m";
	std::cout << std::endl;
}

Form::Form(std::string name, int gradeToBeSigned, int gradeToBeExecuted):
										_name(name),
										_gradeToBeSigned(gradeToBeSigned),
										_gradeToBeExecuted(gradeToBeExecuted)
{
	if (_gradeToBeSigned < 1 || _gradeToBeExecuted < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToBeSigned > 150 || _gradeToBeExecuted > 150)
		throw Form::GradeTooLowException();
	_isSigned = false;
	std::cout << "\033[0;35mA form named " << _name << " is created\033[0m";
	std::cout << std::endl;
}

Form::Form(const Form &f):_name(f.getName()),
							_gradeToBeSigned(f.getGradeToBeSigned()),
							_gradeToBeExecuted(f.getGradeToBeExecuted())
{
	(*this) = f;
	std::cout << "\033[0;35mA form named " << _name << " is cloned\033[0m";
	std::cout << std::endl;
}

Form::~Form()
{
	std::cout << "\033[0;35mA form named " << _name << " is destoyed\033[0m";
	std::cout << std::endl;
}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */

std::string	Form::getName(void) const
{
	return (_name);
}

int			Form::getGradeToBeSigned(void) const
{
	return (_gradeToBeSigned);
}

int			Form::getGradeToBeExecuted(void) const
{
	return (_gradeToBeExecuted);
}

bool		Form::getIsSigned(void) const
{
	return (_isSigned);
}


/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	Form::beSigned(const Bureaucrat &b)
{
	if (getIsSigned() == true)
		throw Form::AlreadySignedException();
	else if (b.getGrade() > getGradeToBeSigned())
		throw Form::GradeTooLowException();
	else
		_isSigned = true;
}

/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */
Form	&Form::operator=(const Form &f)
{
	_isSigned = f.getIsSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &output, const Form &f)
{
	output << f.getName() << " : ";
	if (f.getIsSigned() == false)
		output << "not signed." << std::endl;
	else
		output << "signed." << std::endl;
	output << "Minimal Grade to be signed   : " << f.getGradeToBeSigned();
	output << std::endl;
	output << "Minimal Grade to be executed : " << f.getGradeToBeExecuted();
	output << std::endl;
	return (output);

}

/* ************************************************************************** */
/* MISCELLANEOUS                                                              */
/* ************************************************************************** */
const char* Form::GradeTooHighException::what() const throw()
{
	return ("\033[0;31mGrade is too high\033[0m");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("\033[0;31mGrade is too low\033[0m");
}

const char* Form::AlreadySignedException::what() const throw()
{
	return ("\033[0;31mForm is already signed\033[0m");
}
