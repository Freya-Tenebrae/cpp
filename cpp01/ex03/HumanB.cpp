/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/10 16:14:33 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name):_name(name), _weapon(NULL)
{
	// std::string msg;

	// msg = _name + " don't have any weapon...";
	// std::cout << msg << std::endl;
}

HumanB::~HumanB()
{

}

void	HumanB::setWeapon(Weapon &weapon)
{
	// std::string msg;

	_weapon = &weapon;
	// msg = _name + " grab their " + _weapon->getType();
	// std::cout << msg << std::endl;
}

void HumanB::attack(void)
{
	std::string msg;

	if (_weapon == NULL)
		msg = _name + " don't have any weapon to attack";
	else
		msg = _name + " attacks with their " + _weapon->getType();
	std::cout << msg << std::endl;
}
