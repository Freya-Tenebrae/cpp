/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/13 16:50:49 by cmaginot         ###   ########.fr       */
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
		
Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "\033[0;35mCopy assignment operator called\033[0m";
	std::cout << std::endl;
	this->setRawBits(f.getRawBits());
	return (*this);
}
