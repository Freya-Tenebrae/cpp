/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:20:53 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/15 00:06:33 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target):
										AForm("PresidentialPardonForm", 25, 5),
										_target(target)
{

	std::cout << "\033[0;35mA PresidentialPardonForm targetting " << _target;
	std::cout << " is created\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &f):
		AForm(f.getName(), f.getGradeToBeSigned(), f.getGradeToBeExecuted()),
		_target(f.getTarget())
{
	*this = f;
	std::cout << "\033[0;35mA PresidentialPardonForm targetting " << _target;
	std::cout << " is cloned\033[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[0;35mA PresidentialPardonForm targetting " << _target;
	std::cout << " is destroyed\033[0m" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (getIsSigned() == false)
		throw AForm::NotSignedExeption();
	else if (executor.getGrade() > getGradeToBeExecuted())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << getTarget() << " have been pardoned by ";
		std::cout << "Zaphod Beeblebrox." << std::endl;
	}
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const \
													PresidentialPardonForm &f)
{
	(void)f;
	return (*this);
}
