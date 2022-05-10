/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/10 16:05:08 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon hexblade = Weapon("shiny shortsword");
		HumanA arik("Arik", hexblade);
		arik.attack();
		hexblade.setType("heavy claymore");
		arik.attack();
	}
	{
		Weapon bow = Weapon("melodic bow");
		HumanB freya("Freya");
		freya.setWeapon(bow);
		freya.attack();
		bow.setType("broken bow");
		freya.attack();
		Weapon sword = Weapon("sword of elegance");
		freya.setWeapon(sword);
		freya.attack();
	}
	return (0);
}