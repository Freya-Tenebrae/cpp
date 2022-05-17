/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/17 18:28:14 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(int argc, char const *argv[])
{
	// ClapTrap c1("Arik");
	// ClapTrap c2("Mummius");
	ScavTrap s1("Aria");
	ScavTrap s2(s1);
	ScavTrap s3;
	s3.setName("Chelcie");

	// std::cout << c1 << std::endl;
	// std::cout << c2 << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;

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

	std::cout << s1 << std::endl;
	s1.takeDamage(250);
	s1.repair();
	s1.attack("Jack");
	std::cout << s1 << std::endl;

	std::cout << s2 << std::endl;
	s2.attack("Jack");
	s2.takeDamage(10);
	s2.repair();
	std::cout << s2 << std::endl;

	std::cout << s3 << std::endl;
	s3.setEnergyPoint(2);
	std::cout << s3 << std::endl;
	s3.attack("Decorative armor");
	s3.repair();
	s3.attack("Decorative armor");
	s3.repair();
	std::cout << s3 << std::endl;

	return (0);
}
