/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/16 16:22:21 by cmaginot         ###   ########.fr       */
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
	_rawBits = raw << _number;
}

Fixed::Fixed(float const raw)
{
	std::cout << "\033[0;35mFloat constructor called\033[0m" << std::endl;
	_rawBits = roundf(raw * (1 << _number));
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

int		Fixed::toInt(void) const
{
	// std::cout << "\033[0;35mtoInt member function called\033[0m";
	// std::cout << std::endl;
	return (_rawBits >> _number);
}

float	Fixed::toFloat(void) const
{
	// std::cout << "\033[0;35mtoFloat member function called\033[0m";
	// std::cout << std::endl;
	return (_rawBits / (float)(1 << _number));
}


Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "\033[0;35mCopy assignment operator called\033[0m";
	std::cout << std::endl;
	this->setRawBits(f.getRawBits());
	return (*this);
}

std::ostream	&operator<<(std::ostream &output, const Fixed &f)
{
	output << f.toFloat();
	return (output);	
}
