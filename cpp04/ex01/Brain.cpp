/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/07/26 20:13:54 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

Brain::Brain()
{
	std::cout << "\033[0;35mA Brain is created\033[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";
}

Brain::Brain(const Brain &brain)
{
	(*this) = brain;
	std::cout << "\033[0;35mA Brain is copied\033[0m" << std::endl;
}

Brain::~Brain()
{
	std::cout << "\033[0;35mA Brain is destroyed\033[0m" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "\033[0;35mA Brain is copied (operator =)\033[0m";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		this->setIdea(brain.getIdea(i), i);
	return (*this);
}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */
std::string const	Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return ("");
	else
		return(_ideas[i]);
}

void	Brain::setIdea(std::string const idea, int i)
{
	if (i >= 0 && i < 100)
		_ideas[i] = idea;
}
