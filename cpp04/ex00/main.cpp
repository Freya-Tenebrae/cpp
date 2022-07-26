/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/07/26 14:25:26 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

int main(int argc, char const *argv[])
{
	const Animal* meta = new Animal();
	const Animal* c = new Cat();
	const Animal* d = new Dog();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	meta->makeSound();
	c->makeSound();
	d->makeSound();


	delete meta;

	return (0);
}
