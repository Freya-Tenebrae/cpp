/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/09 15:23:33 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* c = new Cat();
	const Animal* d = new Dog();
	const WrongAnimal* wMeta = new WrongAnimal();
	const WrongAnimal* wC = new WrongCat();

	std::cout  << "Animal       : " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout  << "Cat          : " << c->getType() << std::endl;
	c->makeSound();
	std::cout  << "Dog          : " << d->getType() << std::endl;
	d->makeSound();
	std::cout  << "Wrong Animal : " << wMeta->getType() << std::endl;
	wMeta->makeSound();
	std::cout  << "Wrong Cat    : " << wC->getType() << std::endl;
	wC->makeSound();

	delete meta;
	delete c;
	delete d;
	delete wMeta;
	delete wC;

	return (0);
}
