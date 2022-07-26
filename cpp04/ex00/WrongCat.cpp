/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/07/26 14:50:07 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

WrongCat::WrongCat()
{
	this->setType("WrongCat");
	std::cout << "\033[0;35mA WrongCat is created\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat)
{
	(*this) = wrongCat;
	std::cout << "\033[0;35mA WrongCat is copied\033[0m" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "\033[0;35mA WrongCat is destroyed\033[0m" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
	std::cout << "\033[0;35mA WrongCat is copied (operator =)\033[0m";
	std::cout << std::endl;
	this->setType(wrongCat.getType());
	return (*this);
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	WrongCat::makeSound() const
{
	std::cout << "'M e o w'" << std::endl;
}