/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/07/26 19:04:10 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

Dog::Dog()
{
	this->setType("Dog");
	_brain = new Brain();
	std::cout << "\033[0;35mA Dog is created\033[0m" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	(*this) = dog;
	std::cout << "\033[0;35mA Dog is copied\033[0m" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "\033[0;35mA Dog is destroyed\033[0m" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "\033[0;35mA Dog is copied (operator =)\033[0m";
	std::cout << std::endl;
	this->setType(dog.getType());
	return (*this);
}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */

std::string const	Dog::getIdea(int i)const
{
	return (_brain->getIdea(i));
}

void	Dog::setIdea(std::string const idea, int i)
{
	_brain->setIdea(idea, i);
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	Dog::makeSound() const
{
	std::cout << "'Woof'" << std::endl;
}