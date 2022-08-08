/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/08 17:51:26 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap c1("Arik");
	ClapTrap c2(c1);
	ClapTrap c3;
	c3.setName("Mummius");

	std::cout << c1 << std::endl;
	std::cout << c2 << std::endl;
	std::cout << c3 << std::endl;

	std::cout << c1 << std::endl;
	c1.takeDamage(25);
	c1.repair();
	c1.attack("Jack");
	std::cout << c1 << std::endl;

	std::cout << c2 << std::endl;
	c2.attack("Jack");
	c2.takeDamage(1);
	c2.repair();
	std::cout << c2 << std::endl;

	std::cout << c3 << std::endl;
	c3.setEnergyPoint(2);
	std::cout << c3 << std::endl;
	c3.attack("Decorative armor");
	c3.repair();
	c3.attack("Decorative armor");
	c3.repair();
	std::cout << c3 << std::endl;

	return (0);
}
