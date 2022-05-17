/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:46:09 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/17 20:10:38 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */
DiamondTrap::DiamondTrap()
{
	setHitPoint(FragTrap::getHitPoint());
	setEnergyPoint(ScavTrap::getEnergyPoint());
	setAttackDamage(FragTrap::getAttackDamage());
	setRepairValue(ScavTrap::getRepairValue());
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
	(*this) = diamondTrap;
}

DiamondTrap::DiamondTrap(const std::string name)
{
	ClapTrap::setName(name + "_clap_name");
	setName(name);
	setHitPoint(FragTrap::getHitPoint());
	setEnergyPoint(ScavTrap::getEnergyPoint());
	setAttackDamage(FragTrap::getAttackDamage());
	setRepairValue(ScavTrap::getRepairValue());
}

DiamondTrap::~DiamondTrap()
{

}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::repair()
{
	FragTrap::repair();
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	ScavTrap::takeDamage(amount);
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	FragTrap::beRepaired(amount);
}

void	DiamondTrap::whoAmI()
{
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mIf my name is " << getName() << ", and my ClapTrap";
	std::cout << " name is" << ClapTrap::getName() << ", who am i ???";
	std::cout << "\033[0m\"" << std::endl;
	std::cout << getName() << " questionned itself another time";
	std::cout << std::endl;
}
