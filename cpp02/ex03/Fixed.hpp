/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/16 18:44:48 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_number = 8;

	public:
		/* ****************************************************************** */
		/* CONSTRUCTOR & DESTRUCTOR                                           */
		/* ****************************************************************** */
		Fixed();
		Fixed(const Fixed &f);
		Fixed(int const raw);
		Fixed(float const raw);
		~Fixed();

		/* ****************************************************************** */
		/* GETTER & SETTER                                                    */
		/* ****************************************************************** */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/* ****************************************************************** */
		/* MEMBER FUNCTION                                                    */
		/* ****************************************************************** */
		float				toFloat(void) const;
		int					toInt(void) const;

		static Fixed		&min(Fixed &f1, Fixed &f2);
		static Fixed const	&min(const Fixed &f1, const Fixed &f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
		static Fixed const	&max(const Fixed &f1, const Fixed &f2);

		/* ****************************************************************** */
		/* OPERATOR OVERLOADING                                               */
		/* ****************************************************************** */
		Fixed		&operator=(const Fixed &f);

		bool const	operator>(const Fixed &f);
		bool const	operator<(const Fixed &f);
		bool const	operator>=(const Fixed &f);
		bool const	operator<=(const Fixed &f);
		bool const	operator==(const Fixed &f);
		bool const	operator!=(const Fixed &f);

		Fixed		operator+(const Fixed &f);
		Fixed		operator-(const Fixed &f);
		Fixed		operator*(const Fixed &f);
		Fixed		operator/(const Fixed &f);

		Fixed		operator++();
		Fixed		operator++(int);
		Fixed		operator--();
		Fixed		operator--(int);
};//!Fixed

std::ostream	&operator<<(std::ostream &output, const Fixed &f);

#endif
