/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:20:30 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/15 18:26:20 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
										AForm("RobotomyRequestForm", 72, 45),
										_target("nothing")
{

	std::cout << "\033[0;35mA RobotomyRequestForm targetting nothing";
	std::cout << " is created\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
										AForm("RobotomyRequestForm", 72, 45),
										_target(target)
{

	std::cout << "\033[0;35mA RobotomyRequestForm targetting " << _target;
	std::cout << " is created\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &f):
		AForm(f.getName(), f.getGradeToBeSigned(), f.getGradeToBeExecuted()),
		_target(f.getTarget())
{
	*this = f;
	std::cout << "\033[0;35mA RobotomyRequestForm targetting " << _target;
	std::cout << " is cloned\033[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[0;35mA RobotomyRequestForm targetting " << _target;
	std::cout << " is destroyed\033[0m" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	static int i;
	int random;

	if (getIsSigned() == false)
		throw AForm::NotSignedExeption();
	else if (executor.getGrade() > getGradeToBeExecuted())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << " VRRRRRRRRRRR vrrrRRRRRRRRRRRR VRRRRRRRRrrrrrrrr.... ";
		std::cout << "- The robotomy of " << getTarget();
		std::srand(std::time(0) + i++);
    	random = std::rand();
    	if (random % 2 == 0)
    		std::cout << " is a success!" << std::endl;
    	else
    		std::cout << " failed!" << std::endl;
	}
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const \
													RobotomyRequestForm &f)
{
	(void)f;
	return (*this);
}
