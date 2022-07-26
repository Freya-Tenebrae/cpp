/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/07/26 14:56:54 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

Cat::Cat()
{
	this->setType("Cat");
	std::cout << "\033[0;35mA Cat is created\033[0m" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	(*this) = cat;
	std::cout << "\033[0;35mA Cat is copied\033[0m" << std::endl;
}

Cat::~Cat()
{
	std::cout << "\033[0;35mA Cat is destroyed\033[0m" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "\033[0;35mA Cat is copied (operator =)\033[0m";
	std::cout << std::endl;
	this->setType(cat.getType());
	return (*this);
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	Cat::makeSound() const
{
	std::cout << "'Meow'" << std::endl;
}