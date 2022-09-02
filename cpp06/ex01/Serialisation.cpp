/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialisation.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:31:11 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/02 18:00:49 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialisation.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */
Serialisation::Serialisation()
{
	std::cout << "\033[0;35mA Serialisation is created\033[0m" << std::endl;
}

Serialisation::Serialisation(const Serialisation &s)
{
	*this = s;
	std::cout << "\033[0;35mA Serialisation is duplicated\033[0m" << std::endl;
}

Serialisation::~Serialisation()
{
	std::cout << "\033[0;35mA Serialisation is destroyed\033[0m" << std::endl;
}

/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */
Serialisation	&Serialisation::operator=(const Serialisation &s)
{
	(void)s;
	return (*this);
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
uintptr_t	Serialisation::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serialisation::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
