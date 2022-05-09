/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/09 18:01:14 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon):_name(name), _weapon(weapon)
{

}

HumanA::~HumanA()
{

}

void HumanA::attack(void)
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}
