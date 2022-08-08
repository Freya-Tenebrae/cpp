/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:46:09 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/08 13:32:04 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

	public:
		/* ****************************************************************** */
		/* CONSTRUCTOR & DESTRUCTOR                                           */
		/* ****************************************************************** */
		DiamondTrap();
		DiamondTrap(const DiamondTrap &diamondTrap);
		DiamondTrap(const std::string name);
		~DiamondTrap();

		/* ****************************************************************** */
		/* GETTER & SETTER                                                    */
		/* ****************************************************************** */
		std::string const	getName();
		void				setName(std::string const name);
		
		/* ****************************************************************** */
		/* MEMBER FUNCTION                                                    */
		/* ****************************************************************** */
		void	attack(const std::string& target);
		void	repair();
		void	whoAmI();

};//!DiamondTrap

#endif
