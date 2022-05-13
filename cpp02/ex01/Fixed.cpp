/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/13 19:11:01 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_rawBits(0)
{
	std::cout << "\033[0;35mDefault constructor called\033[0m" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "\033[0;35mCopy constructor called\033[0m" << std::endl;
	(*this) = f;
}

Fixed::Fixed(int const raw)
{
	std::cout << "\033[0;35mInt constructor called\033[0m" << std::endl;
// • Un constructeur prenant un entier constant en paramètre et qui convertit 
// 	celuici en virgule fixe. Le nombre de bits de la partie fractionnaire est 
// 	initialisé à 8 comme dans l’exercice 00.
}

Fixed::Fixed(float const raw)
{
	std::cout << "\033[0;Float constructor called\033[0m" << std::endl;
// • Un constructeur prenant un flottant constant en paramètre et qui convertit
// 	celui-ci en virgule fixe. Le nombre de bits de la partie fractionnaire est 
// 	initialisé à 8 comme dans l’exercice 00.
}


Fixed::~Fixed()
{
	std::cout << "\033[0;35mDestructor called\033[0m" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "\033[0;35mgetRawBits member function called\033[0m";
	std::cout << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "\033[0;35msetRawBits member function called\033[0m";
	std::cout << std::endl;
	_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	std::cout << "\033[0;35mtoFloat member function called\033[0m";
	std::cout << std::endl;
// • Une fonction membre float toFloat( void ) const;
// 	qui convertit la valeur en virgule fixe en nombre à virgule flottante.
}

int		Fixed::toInt(void) const
{
	std::cout << "\033[0;35mtoInt member function called\033[0m";
	std::cout << std::endl;
// • Une fonction membre int toInt( void ) const;
// 	qui convertit la valeur en virgule fixe en nombre entier.
}


Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "\033[0;35mCopy assignment operator called\033[0m";
	std::cout << std::endl;
	this->setRawBits(f.getRawBits());
	return (*this);
}

void	&operator<<(const Fixed &f)
{
// • Une surcharge de l’opérateur d’insertion («) qui insère une représentation 
// 	en virgule flottante du nombre à virgule fixe dans le flux de sortie 
// 	(objet output stream)passé en paramètre.	
}