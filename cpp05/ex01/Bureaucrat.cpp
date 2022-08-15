/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/15 18:19:29 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

Bureaucrat::Bureaucrat():_name(""), _grade(150)
{
	std::cout << "\033[0;35mDefault constructor called. DO NOT USE\033[0m";
	std::cout << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "\033[0;35mA Bureaucrat named " << _name;
	std::cout << " is recruited\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b):_name(b.getName())
{
	(*this) = b;
	std::cout << "\033[0;35mA Bureaucrat named " << _name;
	std::cout << " is cloned\033[0m" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[0;35mA Bureaucrat named " << _name;
	std::cout << " is fired\033[0m" << std::endl;
}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */

std::string	Bureaucrat::getName(void) const
{
	return(_name);
}

int	Bureaucrat::getGrade(void) const
{
	return(_grade);
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	Bureaucrat::Promoted()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	std::cout << "A Bureaucrat named " << _name << "  is promoted" << std::endl;
}

void	Bureaucrat::Demoted()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	std::cout << "A Bureaucrat named " << _name << "  is demoted" << std::endl;
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << "\033[0;33m" << getName() << " signed " << f.getName();
		std::cout << "\033[0m" << std::endl;
	}
	catch (Form::AlreadySignedException &e)
	{
		std::cerr << getName() << " couldn't sign " << f.getName();
		std::cerr << " because " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << getName() << " couldn't sign " << f.getName();
		std::cerr << " because " << e.what() << std::endl;
	}
}

/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &b)
{
	if (b.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (b.getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = b.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &b)
{
	output << b.getName() << ", bureaucrat grade " << b.getGrade();
	output << std::endl;
	return (output);

}

/* ************************************************************************** */
/* MISCELLANEOUS                                                              */
/* ************************************************************************** */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\033[0;31mGrade is too high\033[0m");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\033[0;31mGrade is too low\033[0m");
}
