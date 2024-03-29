/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/09 14:53:25 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	_complain[0].level = "DEBUG";
	_complain[0].complainLevel = &Harl::debug;
	_complain[1].level = "INFO";
	_complain[1].complainLevel = &Harl::info;
	_complain[2].level = "WARNING";
	_complain[2].complainLevel = &Harl::warning;
	_complain[3].level = "ERROR";
	_complain[3].complainLevel = &Harl::error;
}

Harl::~Harl()
{

}

void	Harl::debug()
{
	std::cout << "\033[1;35m[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I really do!\033[0m" << std::endl << std::endl;
}

void	Harl::info()
{
	std::cout << "\033[1;34m[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn’t be asking for more!\033[0m" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning()
{
	std::cout << "\033[1;33m[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working ";
	std::cout << "here since last month.\033[0m" << std::endl << std::endl;
}

void	Harl::error()
{
	std::cout << "\033[1;31m[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << "\033[0m" << std::endl << std::endl;
}

int	Harl::getNumberedLevel(std::string level)
{
	for (int i = 0; i < _nComplain; i++)
	{
		if (_complain[i].level == level)
			return (i);
	}
	return (_nComplain);
}

void	Harl::totalyFiltered()
{
	std::cout << "\033[1;36m[ Probably complaining about insignificant ";
	std::cout << "problems ]\033[0m" << std::endl << std::endl;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < _nComplain; i++)
	{
		if (_complain[i].level == level)
			return (this->*_complain[i].complainLevel) ();
	}
}

void	Harl::harlFilter(std::string const filter)
{
	int const	levelFiltered = getNumberedLevel(filter);

	switch(levelFiltered)
	{
		case 0:
			complain("DEBUG");
		case 1:
			complain("INFO");
		case 2:
			complain("WARNING");
		case 3:
			complain("ERROR");
			break;
		default:
			totalyFiltered();
	}
}
