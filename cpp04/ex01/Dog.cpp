/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/07/26 15:06:55 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

Dog::Dog()
{
	this->setType("Dog");
	std::cout << "\033[0;35mA Dog is created\033[0m" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	(*this) = dog;
	std::cout << "\033[0;35mA Dog is copied\033[0m" << std::endl;
}

Dog::~Dog()
{
	std::cout << "\033[0;35mA Dog is destroyed\033[0m" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "\033[0;35mA Dog is copied (operator =)\033[0m";
	std::cout << std::endl;
	this->setType(dog.getType());
	return (*this);
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	Dog::makeSound() const
{
	std::cout << "'Woof'" << std::endl;
}