/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/09 16:58:18 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	std::cout << "\033[1;36mMateria tests :\033[0m" << std::endl;
	// const AMateria* meta = new AMateria();
	const AMateria* c = new Cure();
	const AMateria* i = new Ice();
	c->use();
	i->use();

	// delete meta;
	delete c;
	delete i;

}
