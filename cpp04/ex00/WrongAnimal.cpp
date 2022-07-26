/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/07/26 14:50:21 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

WrongAnimal::WrongAnimal():_type("none")
{
	std::cout << "\033[0;35mAn WrongAnimal is created\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
	(*this) = WrongAnimal;
	std::cout << "\033[0;35mAn WrongAnimal is copied\033[0m" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[0;35mAn WrongAnimal is destroyed\033[0m" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal)
{
	std::cout << "\033[0;35mAn WrongAnimal is copied (operator =)\033[0m";
	std::cout << std::endl;
	this->setType(WrongAnimal.getType());
	return (*this);
}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */
std::string const	WrongAnimal::getType() const
{
	return(_type);
}

void	WrongAnimal::setType(std::string const type)
{
	_type = type;
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	WrongAnimal::makeSound() const
{
	std::cout << "'bip bip bip'" << std::endl;
}