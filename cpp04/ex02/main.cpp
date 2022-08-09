/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/09 16:14:39 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "\033[1;36mPrevious test :\033[0m" << std::endl;
	//const AAnimal* meta = new AAnimal();
	const AAnimal* c = new Cat();
	const AAnimal* d = new Dog();

	//std::cout  << "AAnimal : " << meta->getType() << std::endl;
	//meta->makeSound();
	std::cout  << "Cat    : " << c->getType() << std::endl;
	c->makeSound();
	std::cout  << "Dog    : " << d->getType() << std::endl;
	d->makeSound();
	//delete meta;
	delete c;
	delete d;

	std::cout << std::endl << "\033[1;36mBrain test :\033[0m" << std::endl;
	Brain* b = new Brain();
	Cat* cat = new Cat();


	b->setIdea("makeSound", 1);
	b->setIdea("meowing for headpat", 42);
	b->setIdea("barking to open the door", 66);
	cat->setIdea("makeSound", 1);
	cat->setIdea("meowing for headpat", 42);
	cat->setIdea("meowing to open the door", 66);
	std::cout << "Brain wrong idea : " << b->getIdea(-4) << std::endl;
	std::cout << "Brain idea 1     : " << b->getIdea(1) << std::endl;
	std::cout << "Brain wrong idea : " << b->getIdea(11) << std::endl;
	std::cout << "Brain idea 42    : " << b->getIdea(42) << std::endl;
	std::cout << "Brain idea 66    : " << b->getIdea(66) << std::endl;
	std::cout << "Brain wrong idea : " << b->getIdea(111) << std::endl;
	std::cout << "Cat wrong idea   : " << cat->getIdea(-4) << std::endl;
	std::cout << "Cat idea 1       : " << cat->getIdea(1) << std::endl;
	std::cout << "Cat wrong idea   : " << cat->getIdea(11) << std::endl;
	std::cout << "Cat idea 42      : " << cat->getIdea(42) << std::endl;
	std::cout << "Cat idea 66      : " << cat->getIdea(66) << std::endl;
	std::cout << "Cat wrong idea   : " << cat->getIdea(111) << std::endl;

	delete b;
	delete cat;

	std::cout << std::endl << "\033[1;36mWith a table :\033[0m" << std::endl;

	AAnimal *tAnimal[6];
	std::cout << "\033[1;36mfill half with cat\033[0m" << std::endl;
	for (int i = 0; i < 3; i++)
		tAnimal[i] = new Cat();
	std::cout << "\033[1;36mfill other half with dog\033[0m" << std::endl;
	for (int i = 3; i < 6; i++)
		tAnimal[i] = new Dog();
	std::cout << "\033[1;36mdelete\033[0m" << std::endl;
	for (int i = 0; i < 6; i++)
		delete tAnimal[i];
	std::cout << std::endl << "\033[1;36mEnd of tests\033[0m" << std::endl;
	return (0);
}
