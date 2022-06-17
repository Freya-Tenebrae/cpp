/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/06/17 16:04:20 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(int argc, char const *argv[])
{
	// ClapTrap c1("Arik");
	// ClapTrap c2("Mummius");
	// ScavTrap s1("Aria");
	// ScavTrap s2("Chelcie");
	// FragTrap f1("Freya");
	// FragTrap f2("Amarath");
	DiamondTrap d1("Helrindhal");
	DiamondTrap d2(d1);
	DiamondTrap d3;
	d3.DiamondTrap::setName("yuki");

	// std::cout << c1 << std::endl;
	// std::cout << c2 << std::endl;
	// std::cout << s1 << std::endl;
	// std::cout << s2 << std::endl;
	// std::cout << f1 << std::endl;
	// std::cout << f2 << std::endl;

	// std::cout << c1 << std::endl;
	// c1.takeDamage(25);
	// c1.repair();
	// c1.attack("Jack");
	// std::cout << c1 << std::endl;

	// std::cout << c2 << std::endl;
	// c2.setEnergyPoint(2);
	// std::cout << c2 << std::endl;
	// c2.attack("Decorative armor");
	// c2.repair();
	// c2.attack("Decorative armor");
	// c2.repair();
	// std::cout << c2 << std::endl;

	// std::cout << s1 << std::endl;
	// s1.takeDamage(250);
	// s1.repair();
	// s1.attack("Jack");
	// std::cout << s1 << std::endl;

	// std::cout << s2 << std::endl;
	// s2.setEnergyPoint(2);
	// std::cout << s2 << std::endl;
	// s2.guardGate();
	// s2.attack("Decorative armor");
	// s2.repair();
	// s2.attack("Decorative armor");
	// s2.repair();
	// std::cout << s2 << std::endl;

	// std::cout << f1 << std::endl;
	// f1.takeDamage(250);
	// f1.repair();
	// f1.attack("Jack");
	// std::cout << f1 << std::endl;

	// std::cout << f2 << std::endl;
	// f2.setEnergyPoint(2);
	// std::cout << f2 << std::endl;
	// f2.highFivesGuys();
	// f2.attack("Decorative armor");
	// f2.repair();
	// f2.attack("Decorative armor");
	// f2.repair();
	// std::cout << f2 << std::endl;

	std::cout << d1 << std::endl;
	d1.guardGate();
	d1.takeDamage(250);
	d1.repair();
	d1.attack("Jack");
	std::cout << d1 << std::endl;

	std::cout << d2 << std::endl;
	d2.attack("Jack");
	d2.takeDamage(10);
	d2.repair();
	d2.highFivesGuys();
	std::cout << d2 << std::endl;

	std::cout << d3 << std::endl;
	d3.setEnergyPoint(2);
	std::cout << d3 << std::endl;
	d3.attack("Decorative armor");
	d3.repair();
	d3.attack("Decorative armor");
	d3.repair();
	d3.whoAmI();
	std::cout << d3 << std::endl;

	return (0);
}

//https://borderlands.fandom.com/wiki/Claptrap/Quotes