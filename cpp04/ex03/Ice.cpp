/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:07:53 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/10 18:39:21 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

Ice::Ice()
{
	this->setType("ice");
	std::cout << "\033[0;35mAn Ice Materia is created\033[0m" << std::endl;
}

// Ice::Ice(std::string const & type):_type(type)
// {
// 	std::cout << "\033[0;35mAn Ice Materia is created\033[0m" << std::endl;
// }

Ice::Ice(const Ice &ice)
{
	(*this) = ice;
	std::cout << "\033[0;35mAn Ice Materia is copied\033[0m" << std::endl;
}

Ice::~Ice()
{
	std::cout << "\033[0;35mAn Ice Materia is destroyed\033[0m" << std::endl;
}

Ice		&Ice::operator=(const Ice &ice)
{
	std::cout << "\033[0;35mAn Ice Materia is copied (operator =)\033[0m";
	std::cout << std::endl;
	this->setType(ice.getType());
	return (*this);
}

/* ************************************************************************** */
/* FUNCTION                                                                   */
/* ************************************************************************** */
AMateria* Ice::clone() const
{
	AMateria* ice = new Ice();
	return (ice);
}

void Ice::use(ICharacter& target) const
{
	std::cout << "\033[0;96m" << this->getType();
	std::cout << "\033[0;0m : shoots an ice bolt at \033[0;31m";
	std::cout << target.getName() << "\033[0;0m" << std::endl;
}
