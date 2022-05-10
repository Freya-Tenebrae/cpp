/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/10 16:14:18 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_name(name), _weapon(weapon)
{
	// std::string msg;

	// msg = _name + " pick up their " + _weapon.getType();
	// std::cout << msg << std::endl;
}

HumanA::~HumanA()
{

}

void HumanA::attack(void)
{
	std::string msg;

	msg = _name + " attacks with their " + _weapon.getType();
	std::cout << msg << std::endl;
}
