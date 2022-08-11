/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/11 14:56:28 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

Cat::Cat()
{
	this->setType("Cat");
	_brain = new Brain();
	std::cout << "\033[0;35mA Cat is created\033[0m" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	(*this) = cat;
	std::cout << "\033[0;35mA Cat is copied\033[0m" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "\033[0;35mA Cat is destroyed\033[0m" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "\033[0;35mA Cat is copied (operator =)\033[0m";
	std::cout << std::endl;
	this->setType(cat.getType());
	this->setBrain(cat.getBrain());
	return (*this);
}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */


Brain const	*Cat::getBrain()const
{
	return (_brain);
}

void	Cat::setBrain(const Brain *brain)
{
	*_brain = *brain;
}

std::string const	Cat::getIdea(int i)const
{
	return (_brain->getIdea(i));
}

void	Cat::setIdea(std::string const idea, int i)
{
	_brain->setIdea(idea, i);
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	Cat::makeSound() const
{
	std::cout << "'Meow'" << std::endl;
}