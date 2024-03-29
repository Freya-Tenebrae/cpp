/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/08 13:29:02 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */
ScavTrap::ScavTrap():ClapTrap()
{
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	setRepairValue(25);
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mWhere is my name Minion ?!\033[0m\"" << std::endl;
	std::cout << "A nameless ScavTrap is constructed... ";
	std::cout << "Give it a name or it'll be realy mad." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ScavTrap)
{
	(*this) = ScavTrap;
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mI will prove to you my robotic superiority!";
	std::cout << "\033[0m\";" << std::endl;
	std::cout << getName() << " (ScavTrap)";
	std::cout << " is dulicated ... now they'll fight each others ?!";
	std::cout << std::endl;
}

ScavTrap::ScavTrap(const std::string name):ClapTrap(name)
{
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	setRepairValue(25);
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mMinion, why did you run?\033[0m\"" << std::endl;
	std::cout << getName() << " (ScavTrap) is constructed... ";
	std::cout << "Maybe it'll let you alone if you run far away" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mCrap happens.\033[0m\"";
	std::cout << std::endl;
	std::cout << getName() << " (ScavTrap) have beed broken";
	std::cout << std::endl;
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	ScavTrap::attack(const std::string& target)
{
	if (getHitPoint() <= 0)
	{
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mThis could've gone better!\"";
		std::cout << "\033[0m" << std::endl;
		std::cout << getName() << " is unconscious, it cannot attack";
		std::cout << std::endl;
	}
	else if (getEnergyPoint() <= 0)
	{
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mOh well.\033[0m\"" << std::endl;
		std::cout << getName() << " tried to attack but fall on the ground";
		std::cout << " out of ennergy." << std::endl;
	}
	else
	{
		setEnergyPoint(getEnergyPoint() -1);
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mExploded!\033[0m\"" << std::endl;
		std::cout << getName() << " attacks " << target << ", causing ";
		std::cout << "\033[0;31m" << getAttackDamage();
		std::cout << "\033[0m points of damage!" << std::endl;
	}
}

void	ScavTrap::repair()
{
	if (getHitPoint() <= 0)
	{
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mThis could've gone better!\"";
		std::cout << "\033[0m" << std::endl;
		std::cout << getName() << " is unconscious, it cannot repaired itself";
		std::cout << std::endl;
	}
	else if (getEnergyPoint() <= 0)
	{
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mOh well.\033[0m\"";
		std::cout << std::endl;
		std::cout << getName() << " tried to repaired itself but fall on the ";
		std::cout << "ground out of ennergy." << std::endl;
	}
	else
	{
		setEnergyPoint(getEnergyPoint() -1);
		beRepaired(getRepairValue());
	}
}

void	ScavTrap::guardGate()
{
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mI can do more than guard a gate! We CL4P-TP units";
	std::cout << " can be programmed to do anything from open doors to ";
	std::cout << "ninja-sassinate highly important Janitory officals!?";
	std::cout << "\033[0m\"" << std::endl;
	std::cout << getName() << " are now a Gate Keeper" << std::endl;
}