/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/09 17:18:51 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name):_name(name), _weapon(NULL)
{

}

HumanB::~HumanB()
{

}

void	HumanB::setWeapon(Weapon weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void)
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon->getType() << std::endl;
}
