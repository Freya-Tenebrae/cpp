/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/07/26 20:38:53 by cmaginot         ###   ########.fr       */
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

AAnimal::AAnimal(const AAnimal &Aanimal)
{
	(*this) = Aanimal;
	std::cout << "\033[0;35mAn Abstract Animal is copied\033[0m" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "\033[0;35mAn Abstract Animal is destroyed\033[0m" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &Aanimal)
{
	std::cout << "\033[0;35mAn Abstract Animal is copied (operator =)\033[0m";
	std::cout << std::endl;
	this->setType(Aanimal.getType());
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
