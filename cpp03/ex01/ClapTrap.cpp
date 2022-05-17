/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/17 18:38:24 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */
ClapTrap::ClapTrap():_name("Nameless Claptrap")
{
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mMinion?\033[0m\"" << std::endl;
	std::cout << "A nameless Claptrap is constructed... ";
	std::cout << "Give him a name or he'll be sad." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	(*this) = clapTrap;
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mThere is two of me ... nooooooooooooo!\033[0m\"";
	std::cout << std::endl;
	std::cout << getName();
	std::cout << " is dulicated ... how can you find the real one now ?!";
	std::cout << std::endl;
}

ClapTrap::ClapTrap(const std::string name):_name(name)
{
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mMinion!\033[0m\"" << std::endl;
	std::cout << getName() << " is constructed... ";
	std::cout << "Be ready to become his \"minion\"" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mI'll die the way I lived: annoying!\033[0m\"";
	std::cout << std::endl;
	std::cout << getName() << " have beed dismantled";
	std::cout << std::endl;
}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */
std::string const	ClapTrap::getName()
{
	return(_name);
}

int const	ClapTrap::getHitPoint()
{
	return(_hitPoint);
}

int const	ClapTrap::getEnergyPoint()
{
	return(_energyPoint);
}

int const	ClapTrap::getAttackDamage()
{
	return(_attackDamage);
}

int const	ClapTrap::getRepairValue()
{
	return(_repairValue);
}

void	ClapTrap::setName(std::string const name)
{
	_name = name;
}

void	ClapTrap::setHitPoint(int const hitPoint)
{
	if (hitPoint < 0)
		_hitPoint = 0;
	else
		_hitPoint = hitPoint;
}

void	ClapTrap::setEnergyPoint(int const energyPoint)
{
	if (energyPoint < 0)
		_energyPoint = 0;
	else
		_energyPoint = energyPoint;
}

void	ClapTrap::setAttackDamage(int const attackDamage)
{
	if (attackDamage < 0)
		_attackDamage = 0;
	else
		_attackDamage = attackDamage;
}

void	ClapTrap::setRepairValue(int const repairValue)
{
	if (repairValue < 0)
		_repairValue = 0;
	else
		_repairValue = repairValue;
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	ClapTrap::attack(const std::string& target)
{
	if (getHitPoint() <= 0)
	{
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mevent unconscious I'll not stop talking!\"";
		std::cout << "\033[0m" << std::endl;
		std::cout << getName() << " is unconscious, he cannot attack";
		std::cout << std::endl;
	}
	else if (getEnergyPoint() <= 0)
	{
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mNo fair! I wasn't ready.\033[0m\"" << std::endl;
		std::cout << getName() << " tried to attack but fall on the ground";
		std::cout << " out of ennergy." << std::endl;
	}
	else
	{
		setEnergyPoint(getEnergyPoint() -1);
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mTake that!\033[0m\"" << std::endl;
		std::cout << getName() << " attacks " << target << ", causing ";
		std::cout << "\033[0;31m" << getAttackDamage();
		std::cout << "\033[0m points of damage!" << std::endl;
	}
}

void	ClapTrap::repair()
{
	if (getHitPoint() <= 0)
	{
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mevent unconscious I'll not stop talking!\"";
		std::cout << "\033[0m" << std::endl;
		std::cout << getName() << " is unconscious, he cannot repaired himself";
		std::cout << std::endl;
	}
	else if (getEnergyPoint() <= 0)
	{
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mNo fair! I wasn't ready.\033[0m\"";
		std::cout << std::endl;
		std::cout << getName() << " tried to repaired himself but fall on the ";
		std::cout << "ground out of ennergy." << std::endl;
	}
	else
	{
		setEnergyPoint(getEnergyPoint() -1);
		beRepaired((getRepairValue()));
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	setHitPoint(getHitPoint() - amount);
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mWhy do I even feel pain?!\033[0m\"";
	std::cout << std::endl;
	std::cout << getName() << " take \033[0;31m" << amount;
	std::cout << "\033[0m hit point!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	setHitPoint(getHitPoint() + amount);
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mHealsies!\033[0m\"" << std::endl;
	std::cout << getName() << " is repaired for \033[0;32m";
	std::cout << amount << "\033[0m hit point!" << std::endl;
}

/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &output, ClapTrap &ct)
{
	output << ct.getName() << " have \033[0;31m" << ct.getHitPoint();
	output << "HP\033[0m, \033[0;34m" << ct.getEnergyPoint();
	output << " EP\033[0m, \033[0;33m";
	output << ct.getAttackDamage() << "AD\033[0m, \033[0;36m";
	output << ct.getRepairValue() << " RV\033[0m.";
	return (output);	
}