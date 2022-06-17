/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:46:09 by cmaginot          #+#    #+#             */
/*   Updated: 2022/06/17 16:04:11 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */
DiamondTrap::DiamondTrap()
{
	this->ClapTrap::setHitPoint(FragTrap::getHitPoint());
	this->ClapTrap::setEnergyPoint(ScavTrap::getEnergyPoint());
	this->ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
	this->ClapTrap::setRepairValue(ScavTrap::getRepairValue());
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
	(*this) = diamondTrap;
}

DiamondTrap::DiamondTrap(const std::string name)
{
	ClapTrap::setName(name + "_clap_name");
	this->_name = name;
	this->ClapTrap::setHitPoint(FragTrap::getHitPoint());
	this->ClapTrap::setEnergyPoint(ScavTrap::getEnergyPoint());
	this->ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
	this->ClapTrap::setRepairValue(ScavTrap::getRepairValue());
}

DiamondTrap::~DiamondTrap()
{

}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */
std::string const	DiamondTrap::getName()
{
	return(this->_name);
}

void	DiamondTrap::setName(std::string const name)
{
	ClapTrap::setName(name + "_clap_name");
	this->_name = name;
}

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
	std::cout << ClapTrap::getName() << " : \"";
	std::cout << "\033[0;35mIf my name is " << this->getName();
	std::cout << ", and my ClapTrap name is" << ClapTrap::getName();
	std::cout << ", who am i ???" << "\033[0m\"" << std::endl;
	std::cout << ClapTrap::getName() << " questionned itself for the 5th";
	std::cout << " time today" << std::endl;
}
