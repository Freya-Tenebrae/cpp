/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:17:00 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/11 15:04:42 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character():_name("nameless")
{
	std::cout << "\033[0;35mA nameless Character is created\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		_materiaContainer[i] = NULL;
}

Character::Character(const std::string name):_name(name)
{
	std::cout << "\033[0;35m" << getName() << " is created\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		_materiaContainer[i] = NULL;
}

Character::Character(const Character &character)
{
	std::cout << character.getName() << " is duplicated\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (character.getMateria(i) != NULL)
			_materiaContainer[i] = character.getMateria(i)->clone();
	}
	_name = character.getName();
}

Character::~Character()
{
	std::cout << "\033[0;35m" << getName() << " is destroyed\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_materiaContainer[i] != NULL)
			delete _materiaContainer[i];
	}
}

Character		&Character::operator=(const Character &character)
{
	std::cout << "\033[0;35m" << getName() << "\033[0m become ";
	std::cout << character.getName() << "\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_materiaContainer[i] != NULL)
			delete _materiaContainer[i];
		if (character.getMateria(i) != NULL)
			_materiaContainer[i] = character.getMateria(i)->clone();
	}
	_name = character.getName();
	return (*this);
}

std::string const & Character::getName() const
{
	return (_name);
}

AMateria *	Character::getMateria(int idx) const
{
	if (idx >= 0 && idx < 3 && _materiaContainer[idx] != NULL)
		return (_materiaContainer[idx]);
	return (NULL);
}


void Character::equip(AMateria* m)
{
	if (m != NULL)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_materiaContainer[i] == NULL)
			{
				_materiaContainer[i] = m;
				std::cout << "\033[0;31m" << getName() << "\"\033[0m equip ";
				std::cout << "\"\033[0;33m" << m->getType() << "\033[0m\"";
				std::cout << " in slot " << i << std::endl;
				break;
			}
			else if (i == 3)
			{
				std::cout << "the inventory of \"\033[0;31m" << getName();
				std::cout << "\"\033[0m can't learn more than 4 Materia";
				std::cout << std::endl;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 3 && _materiaContainer[idx] != NULL)
	{
		std::cout << "\033[0;31m" << getName() << "\"\033[0m unequip ";
		std::cout << "\"\033[0;33m" << _materiaContainer[idx]->getType();
		std::cout << "\033[0m\" at slot " << idx << std::endl;
		_materiaContainer[idx] = NULL;
	}
	else
	{
		std::cout << "\033[0;31m" << getName() << "\"\033[0m don't have a ";
		std::cout << "materia to unequip here" << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 3 && _materiaContainer[idx] != NULL)
	{
		std::cout << "\033[0;31m" << getName() << "\"\033[0m use ";
		_materiaContainer[idx]->use(target);
	}
	else
	{
		std::cout << "\033[0;31m" << getName() << "\"\033[0m don't have a ";
		std::cout << "materia to use here" << std::endl;
	}
}
