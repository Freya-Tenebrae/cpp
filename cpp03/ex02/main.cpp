/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/17 19:35:35 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(int argc, char const *argv[])
{
	// ClapTrap c1("Arik");
	// ClapTrap c2("Mummius");
	// ScavTrap s1("Aria");
	// ScavTrap s2("Chelcie");
	FragTrap f1("Freya");
	FragTrap f2(f1);
	FragTrap f3;
	f3.setName("Amarath");

	// std::cout << c1 << std::endl;
	// std::cout << c2 << std::endl;
	// std::cout << s1 << std::endl;
	// std::cout << s2 << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;

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

	std::cout << f1 << std::endl;
	f1.takeDamage(250);
	f1.repair();
	f1.attack("Jack");
	std::cout << f1 << std::endl;

	std::cout << f2 << std::endl;
	f2.attack("Jack");
	f2.takeDamage(10);
	f2.repair();
	f2.highFivesGuys();
	std::cout << f2 << std::endl;

	std::cout << f3 << std::endl;
	f3.setEnergyPoint(2);
	std::cout << f3 << std::endl;
	f3.attack("Decorative armor");
	f3.repair();
	f3.attack("Decorative armor");
	f3.repair();
	std::cout << f3 << std::endl;

	return (0);
}
