/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/08 16:38:01 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AAnimal.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

AAnimal::AAnimal():_type("none")
{
	std::cout << "\033[0;35mAn Abstract Animal is created\033[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &aAnimal)
{
	(*this) = aAnimal;
	std::cout << "\033[0;35mAn Abstract Animal is copied\033[0m" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "\033[0;35mAn Abstract Animal is destroyed\033[0m" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &aAnimal)
{
	std::cout << "\033[0;35mAn Abstract Animal is copied (operator =)\033[0m";
	std::cout << std::endl;
	this->setType(aAnimal.getType());
	return (*this);
}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */
std::string const	AAnimal::getType() const
{
	return(_type);
}

void	AAnimal::setType(std::string const type)
{
	_type = type;
}
