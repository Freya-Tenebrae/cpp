/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:59:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/09 17:30:48 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

AMateria::AMateria():_type("empty")
{
	std::cout << "\033[0;35mAn Abstract empty Materia is created\033[0m" << std::endl;
}

// AMateria::AMateria(std::string const & type):_type(type)
// {
// 	std::cout << "\033[0;35mAn Abstract Materia is created\033[0m" << std::endl;
// }

AMateria::AMateria(const AMateria &aMateria)
{
	(*this) = aMateria;
	std::cout << "\033[0;35mAn Abstract Materia is copied\033[0m" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "\033[0;35mAn Abstract Materia is destroyed\033[0m" << std::endl;
}

AMateria		&AMateria::operator=(const AMateria &aMateria)
{
	std::cout << "\033[0;35mAn Abstract Materia is copied (operator =)\033[0m";
	std::cout << std::endl;
	this->setType(aMateria.getType());
	return (*this);
}


/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */

std::string const &	AMateria::getType() const
{
	return(_type);
}

void	AMateria::setType(std::string const type)
{
	_type = type;
}
