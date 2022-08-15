/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:31:11 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/15 02:42:13 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

AForm::AForm(std::string name, int gradeToBeSigned, int gradeToBeExecuted):
										_name(name),
										_gradeToBeSigned(gradeToBeSigned),
										_gradeToBeExecuted(gradeToBeExecuted)
{
	if (_gradeToBeSigned < 1 || _gradeToBeExecuted < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeToBeSigned > 150 || _gradeToBeExecuted > 150)
		throw AForm::GradeTooLowException();
	_isSigned = false;
	std::cout << "\033[0;35mA form named " << _name << " is created\033[0m";
	std::cout << std::endl;
}

AForm::AForm(const AForm &f):_name(f.getName()),
							_gradeToBeSigned(f.getGradeToBeSigned()),
							_gradeToBeExecuted(f.getGradeToBeExecuted())
{
	(*this) = f;
	std::cout << "\033[0;35mA form named " << _name << " is cloned\033[0m";
	std::cout << std::endl;
}

AForm::~AForm()
{
	std::cout << "\033[0;35mA form named " << _name << " is destoyed\033[0m";
	std::cout << std::endl;
}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */

std::string	AForm::getName(void) const
{
	return (_name);
}

int			AForm::getGradeToBeSigned(void) const
{
	return (_gradeToBeSigned);
}

int			AForm::getGradeToBeExecuted(void) const
{
	return (_gradeToBeExecuted);
}

bool		AForm::getIsSigned(void) const
{
	return (_isSigned);
}


/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	AForm::beSigned(const Bureaucrat &b)
{
	if (getIsSigned() == true)
		throw AForm::AlreadySignedException();
	else if (b.getGrade() > getGradeToBeSigned())
		throw AForm::GradeTooLowException();
	else
		_isSigned = true;
}

/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */
AForm	&AForm::operator=(const AForm &f)
{
	_isSigned = f.getIsSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &output, const AForm &f)
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
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("\033[0;31mGrade is too high\033[0m");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("\033[0;31mGrade is too low\033[0m");
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return ("\033[0;31mForm is already signed\033[0m");
}

const char* AForm::NotSignedExeption::what() const throw()
{
	return ("\033[0;31mThe form isn't signed\033[0m");
}
