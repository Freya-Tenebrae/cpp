/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/07/26 14:56:59 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

Animal::Animal():_type("none")
{
	std::cout << "\033[0;35mAn Animal is created\033[0m" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	(*this) = animal;
	std::cout << "\033[0;35mAn Animal is copied\033[0m" << std::endl;
}

Animal::~Animal()
{
	std::cout << "\033[0;35mAn Animal is destroyed\033[0m" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "\033[0;35mAn Animal is copied (operator =)\033[0m";
	std::cout << std::endl;
	this->setType(animal.getType());
	return (*this);
}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */
std::string const	Animal::getType() const
{
	return(_type);
}

void	Animal::setType(std::string const type)
{
	_type = type;
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	Animal::makeSound() const
{
	std::cout << "'...'" << std::endl;
}