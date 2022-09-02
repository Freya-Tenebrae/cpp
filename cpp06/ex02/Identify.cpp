/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:31:11 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/02 19:09:25 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */
Identify::Identify()
{
	std::cout << "\033[0;35mIdentify is created\033[0m" << std::endl;
}

Identify::Identify(const Identify &i)
{
	*this = i;
	std::cout << "\033[0;35mIdentify is duplicated\033[0m" << std::endl;
}

Identify::~Identify()
{
	std::cout << "\033[0;35mIdentify is destroyed\033[0m" << std::endl;
}


/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */
Identify	&Identify::operator=(const Identify &i)
{
	(void)i;
	return (*this);
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
Base	*Identify::generate(void)
{
	static int i = 0;
	int random;

	std::srand(std::time(0) + i);
	i++;
	random = std::rand();
	if (random % 3 == 0)
		return (new A());
	else if (random % 3 == 1)
		return (new B());
	else
		return (new C());
}

void	Identify::identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "\033[0;32mid * : \033[0;33mA\033[0m" << std::endl;
	if (dynamic_cast<B *>(p) != NULL)
		std::cout << "\033[0;32mid * : \033[0;33mB\033[0m" << std::endl;
	if (dynamic_cast<C *>(p) != NULL)
		std::cout << "\033[0;32mid * : \033[0;33mC\033[0m" << std::endl;
}

void	Identify::identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "\033[0;32mid & : \033[0;33mA\033[0m" << std::endl;
		(void)a;
	}
	catch (std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout << "\033[0;32mid & : \033[0;33mB\033[0m" << std::endl;
			(void)b;
		}
		catch (std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				std::cout << "\033[0;32mid & : \033[0;33mC\033[0m" << std::endl;
				(void)c;
			}
			catch (std::exception& e)
			{
			}
		}
	}
}
