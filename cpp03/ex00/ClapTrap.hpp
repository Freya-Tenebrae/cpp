/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/17 16:46:42 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hitPoint = 10;
		int			_energyPoint = 10;
		int			_attackDamage = 0;
		int			_repairValue = 1;

	public:
		/* ****************************************************************** */
		/* CONSTRUCTOR & DESTRUCTOR                                           */
		/* ****************************************************************** */
		ClapTrap();
		ClapTrap(const ClapTrap &clapTrap);
		ClapTrap(const std::string name);
		~ClapTrap();

		/* ****************************************************************** */
		/* GETTER & SETTER                                                    */
		/* ****************************************************************** */
		std::string const	getName();
		int const			getHitPoint();
		int const			getEnergyPoint();
		int const			getAttackDamage();
		int const			getRepairValue();
		void				setName(std::string const name);
		void				setHitPoint(int const hitPoint);
		void				setEnergyPoint(int const energyPoint);
		void				setAttackDamage(int const attackDamage);
		void				setRepairValue(int const repairValue);

		/* ****************************************************************** */
		/* MEMBER FUNCTION                                                    */
		/* ****************************************************************** */
		void	attack(const std::string& target);
		void	repair();
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

};//!ClapTrap
/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */
std::ostream	&operator<<(std::ostream &output, ClapTrap &ct);

#endif
