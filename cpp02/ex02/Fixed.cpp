/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/09 14:59:10 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */

Fixed::Fixed():_rawBits(0)
{
	// std::cout << "\033[0;35mDefault constructor called\033[0m" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	// std::cout << "\033[0;35mCopy constructor called\033[0m" << std::endl;
	(*this) = f;
}

Fixed::Fixed(int const raw)
{
	// std::cout << "\033[0;35mInt constructor called\033[0m" << std::endl;
	_rawBits = raw << _number;
}

Fixed::Fixed(float const raw)
{
	// std::cout << "\033[0;35mFloat constructor called\033[0m" << std::endl;
	_rawBits = roundf(raw * (1 << _number));
}


Fixed::~Fixed()
{
	// std::cout << "\033[0;35mDestructor called\033[0m" << std::endl;
}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */

int	Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */

int		Fixed::toInt(void) const
{
	return (_rawBits >> _number);
}

float	Fixed::toFloat(void) const
{
	return (_rawBits / (float)(1 << _number));
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

Fixed const	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

Fixed const	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */

Fixed &Fixed::operator=(const Fixed &f)
{
	// std::cout << "\033[0;35mCopy assignment operator called\033[0m";
	// std::cout << std::endl;
	this->setRawBits(f.getRawBits());
	return (*this);
}

bool	Fixed::operator>(const Fixed &f)
{
	return (_rawBits > f.getRawBits());
}

bool	Fixed::operator<(const Fixed &f)
{
	return (_rawBits < f.getRawBits());
}

bool	Fixed::operator>=(const Fixed &f)
{
	return (_rawBits >= f.getRawBits());
}

bool	Fixed::operator<=(const Fixed &f)
{
	return (_rawBits <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed &f)
{
	return (_rawBits == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed &f)
{
	return (_rawBits != f.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &f)
{
	Fixed	fthiscpy(*this);

	fthiscpy.setRawBits(_rawBits + f.getRawBits());
	return (fthiscpy);
}

Fixed	Fixed::operator-(const Fixed &f)
{
	Fixed	fthiscpy(*this);

	fthiscpy.setRawBits(_rawBits - f.getRawBits());
	return (fthiscpy);
}

Fixed	Fixed::operator*(const Fixed &f)
{
	Fixed	fthiscpy(*this);
	float	raw1 = toFloat();
	float	raw2 = f.toFloat();

	fthiscpy.setRawBits(roundf((raw1 * raw2) * (1 << _number)));
	return (fthiscpy);
}

Fixed	Fixed::operator/(const Fixed &f)
{
	Fixed	fthiscpy(*this);
	float	raw1 = toFloat();
	float	raw2 = f.toFloat();

	fthiscpy.setRawBits(roundf((raw1 / raw2) * (1 << _number)));
	return (fthiscpy);
}

Fixed	Fixed::operator++()
{
	_rawBits++;
	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	_rawBits++;
	return(tmp);
}

Fixed	Fixed::operator--()
{
	_rawBits--;
	return(*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	_rawBits--;
	return(tmp);
}

std::ostream	&operator<<(std::ostream &output, const Fixed &f)
{
	output << f.toFloat();
	return (output);	
}
