/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:54:40 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/10 15:55:53 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "\033[0;35mA MateriaSource is created\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		_materiaContainer[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
	std::cout << "\033[0;35mA MateriaSource is copied\033[0m" << std::endl;
	(*this) = materiaSource;
}

MateriaSource::~MateriaSource()
{
	std::cout << "\033[0;35mA MateriaSource is destroyed\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_materiaContainer[i] != NULL)
			delete _materiaContainer[i];
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &materiaSource)
{
	std::cout << "\033[0;35mA MateriaSource is copied (operator =)\033[0m";
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		_materiaContainer[i] = materiaSource._materiaContainer[i];
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* aMateria)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materiaContainer[i] == NULL)
		{
			_materiaContainer[i] = aMateria->clone();
			break;
		}
		else if (i == 3)
		{
			std::cout << "the \033[0;34mMateriaSource\033[0m is full and ";
			std::cout << "can't learn more than 4 Materia" << std::endl;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materiaContainer[i] == NULL)
			break;
		else if (_materiaContainer[i]->getType().compare(type) == 0)
			return (_materiaContainer[i]->clone());
	}
	std::cout << "the \033[0;34mMateriaSource\033[0m can't create a ";
	std::cout << "materia it didn't learn" << std::endl;
	return (NULL);
}
