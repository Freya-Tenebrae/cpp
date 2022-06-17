/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/06/17 15:56:58 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */
FragTrap::FragTrap():ClapTrap()
{
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	setRepairValue(10);
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mIf i didn't have a name ... did i really exists ?!";
	std::cout << "\033[0m\"" << std::endl;
	std::cout << "A nameless FragTrap is constructed... ";
	std::cout << "Give it a name or it'll be realy chaotic." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
	(*this) = fragTrap;
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mRegular battle! Or, you know... dance battle.";
	std::cout << "\033[0m\";" << std::endl;
	std::cout << getName();
	std::cout << " is dulicated ... now they'll fight in a dance battle...";
	std::cout << std::endl;
}

FragTrap::FragTrap(const std::string name):ClapTrap(name)
{
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	setRepairValue(10);
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mStair ?! ... NOOOOOOOooooooo ... minion?! ";
	std::cout << "come baaaaaaack\033[0m\"" << std::endl;
	std::cout << getName() << " is constructed... ";
	std::cout << "Maybe you'll lose it if you take a stair" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mArgh arghargh death gurgle gurglegurgle ";
	std::cout << "urgh... death.\033[0m\"" << std::endl;
	std::cout << getName() << " have beed destroyed";
	std::cout << std::endl;
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	FragTrap::attack(const std::string& target)
{
	if (getHitPoint() <= 0)
	{
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mMy assets... frozen!\"";
		std::cout << "\033[0m" << std::endl;
		std::cout << getName() << " is unconscious, it cannot attack";
		std::cout << std::endl;
	}
	else if (getEnergyPoint() <= 0)
	{
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mSo, it's a draw, eh?\033[0m\"" << std::endl;
		std::cout << getName() << " tried to attack but fall on the ground";
		std::cout << " out of ennergy." << std::endl;
	}
	else
	{
		setEnergyPoint(getEnergyPoint() -1);
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mThat looks like it hurts!\033[0m\"" << std::endl;
		std::cout << getName() << " attacks " << target << ", causing ";
		std::cout << "\033[0;31m" << getAttackDamage();
		std::cout << "\033[0m points of damage!" << std::endl;
	}
}

void	FragTrap::repair()
{
	if (getHitPoint() <= 0)
	{
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mMy assets... frozen!\"";
		std::cout << "\033[0m" << std::endl;
		std::cout << getName() << " is unconscious, it cannot repaired itself";
		std::cout << std::endl;
	}
	else if (getEnergyPoint() <= 0)
	{
		std::cout << getName() << " : \"";
		std::cout << "\033[0;35mSo, it's a draw, eh?\033[0m\"";
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

void	FragTrap::takeDamage(unsigned int amount)
{
	setHitPoint(getHitPoint() - amount);
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mMy robotic flesh! AAHH!\033[0m\"";
	std::cout << std::endl;
	std::cout << getName() << " take \033[0;31m" << amount;
	std::cout << "\033[0m hit point!" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	setHitPoint(getHitPoint() + amount);
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mI found health!\033[0m\"";
	std::cout << std::endl;
	std::cout << getName() << " is repaired for \033[0;32m";
	std::cout << amount << "\033[0m hit point!" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mLet's get this party started!";
	std::cout << "\033[0m\"" << std::endl;
	std::cout << getName() << " tried to make an high five with you";
	std::cout << std::endl;
}