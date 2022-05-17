/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/17 18:42:46 by cmaginot         ###   ########.fr       */
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
	std::cout << "Give him a name or he'll be realy mad." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ScavTrap)
{
	(*this) = ScavTrap;
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mI will prove to you my robotic superiority!";
	std::cout << "\033[0m\";" << std::endl;
	std::cout << getName();
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
	std::cout << getName() << " is constructed... ";
	std::cout << "Maybe he'll let you alone if you run far away" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mCrap happens.\033[0m\"";
	std::cout << std::endl;
	std::cout << getName() << " have beed broken";
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
		std::cout << getName() << " is unconscious, he cannot attack";
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
		std::cout << getName() << " is unconscious, he cannot repaired himself";
		std::cout << std::endl;
	}
	else if (getEnergyPoint() <= 0)
	{
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mOh well.\033[0m\"";
		std::cout << std::endl;
		std::cout << getName() << " tried to repaired himself but fall on the ";
		std::cout << "ground out of ennergy." << std::endl;
	}
	else
	{
		setEnergyPoint(getEnergyPoint() -1);
		beRepaired(getRepairValue());
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	setHitPoint(getHitPoint() - amount);
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mOw hohoho, that hurts! Yipes!\033[0m\"";
	std::cout << std::endl;
	std::cout << getName() << " take \033[0;31m" << amount;
	std::cout << "\033[0m hit point!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	setHitPoint(getHitPoint() + amount);
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mHealth! Ooo, what flavor is red?!\033[0m\"";
	std::cout << std::endl;
	std::cout << getName() << " is repaired for \033[0;32m";
	std::cout << amount << "\033[0m hit point!" << std::endl;
}
