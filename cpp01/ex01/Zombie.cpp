/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/09 15:53:58 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie():_name("unnamed zombie")
{
	std::cout << "*" << _name << " has been zombified...*" << std::endl;
}

Zombie::Zombie(std::string name):_name(name)
{
	std::cout << "*" << _name << " has been zombified...*" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "*" << _name << " died...*" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	_name = name;
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
