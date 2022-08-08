/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:46:09 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/08 13:38:31 by cmaginot         ###   ########.fr       */
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
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mWhere is my name Minion ?!\033[0m\"" << std::endl;
	std::cout << "A nameless DiamondTrap is constructed... ";
	std::cout << "Give it a name or it'll be realy confused." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
	(*this) = diamondTrap;
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mBattle?";
	std::cout << "\033[0m\";" << std::endl;
	std::cout << getName() << " (DiamondTrap)";
	std::cout << " is dulicated ... will they fight ???";
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name)
{
	ClapTrap::setName(name + "_clap_name");
	this->_name = name;
	this->ClapTrap::setHitPoint(FragTrap::getHitPoint());
	this->ClapTrap::setEnergyPoint(ScavTrap::getEnergyPoint());
	this->ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
	this->ClapTrap::setRepairValue(ScavTrap::getRepairValue());
	std::cout << getName() << " : \"\033[0;35mStair ?! ... NOOOOOOOooooooo ";
	std::cout << "... minion?! minion...\033[0m\"" << std::endl;
	std::cout << getName() << " (DiamondTrap) is constructed";
	std::cout << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << getName() << " : \"";
	std::cout << "\033[0;35mCrap happens.\033[0m\"";
	std::cout << std::endl;
	std::cout << getName() << " (DiamondTrap) have beed broken";
	std::cout << std::endl;

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

void	DiamondTrap::whoAmI()
{
	std::cout << ClapTrap::getName() << " : \"";
	std::cout << "\033[0;35mIf my name is " << this->getName();
	std::cout << ", and my ClapTrap name is" << ClapTrap::getName();
	std::cout << ", who am i ???" << "\033[0m\"" << std::endl;
	std::cout << ClapTrap::getName() << " questionned itself for the 5th";
	std::cout << " time today" << std::endl;
}
