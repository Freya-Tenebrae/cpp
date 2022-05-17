/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/17 18:35:46 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		/* ****************************************************************** */
		/* CONSTRUCTOR & DESTRUCTOR                                           */
		/* ****************************************************************** */
		ScavTrap();
		ScavTrap(const ScavTrap &scavTrap);
		ScavTrap(const std::string name);
		~ScavTrap();

		/* ****************************************************************** */
		/* MEMBER FUNCTION                                                    */
		/* ****************************************************************** */
		void	attack(const std::string& target);
		void	repair();
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

};//!ScavTrap

#endif

// Plus il y a de ClapTraps, mieux c’est ! C’est pourquoi vous allez créer un 
// robot dérivé du ClapTrap. Il s’appellera ScavTrap et héritera des constructeurs
// et du destructeur de ClapTrap. Toutefois, ses constructeurs, son destructeur et
// son attack() afficheront des messages différents. Après tout, les ClapTraps
// sont conscients de leur individualité.

// ScavTrap aura également une capacité spéciale et unique :
// void guardGate();
// Cette fonction membre affichera un message informant que ScavTrap est entré en
// mode Gate keeper.
// N’oubliez pas d’enrichir vos tests.
