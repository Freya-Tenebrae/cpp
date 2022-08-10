/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:07:50 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/10 15:49:33 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

Cure::Cure()
{
	this->setType("cure");
	std::cout << "\033[0;35mAn Cure Materia is created\033[0m" << std::endl;
}

// Cure::Cure(std::string const & type):_type(type)
// {
// 	std::cout << "\033[0;35mAn Cure Materia is created\033[0m" << std::endl;
// }

Cure::Cure(const Cure &cure)
{
	(*this) = cure;
	std::cout << "\033[0;35mAn Cure Materia is copied\033[0m" << std::endl;
}

Cure::~Cure()
{
	std::cout << "\033[0;35mAn Cure Materia is destroyed\033[0m" << std::endl;
}

Cure		&Cure::operator=(const Cure &cure)
{
	std::cout << "\033[0;35mAn Cure Materia is copied (operator =)\033[0m";
	std::cout << std::endl;
	this->setType(cure.getType());
	return (*this);
}

/* ************************************************************************** */
/* FUNCTION                                                                   */
/* ************************************************************************** */
AMateria* Cure::clone() const
{
	AMateria* cure = new Cure();
	return (cure);
}

void Cure::use(/*ICharacter& target*/) const
{
	std::cout << "\033[0;32m" << this->getType();
	std::cout << "\033[0;0m : heals <name>’s wounds" << std::endl;
}
