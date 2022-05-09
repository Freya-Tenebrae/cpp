/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/09 15:56:10 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie z1 = Zombie("Helrindhal");
	Zombie *z2 =  new Zombie("Mummius");
	Zombie *horde = zombieHorde(7, "adds");

	z1.announce();
	z2->announce();
	delete z2;
	announceHorde(7, horde);
	delete [] horde;
	return (0);
}
