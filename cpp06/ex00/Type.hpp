/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Type.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:31:13 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/02 16:57:53 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_HPP
# define TYPE_HPP

/* ************************************************************************** */
/* INCLUDE                                                                     */
/* ************************************************************************** */
# include <string>
# include <iostream>
# include <sstream>
# include <limits>
# include <cmath>

/* ************************************************************************** */
/* DEFINE                                                                     */
/* ************************************************************************** */
# define T_CHAR 1
# define T_INT 2
# define T_FLOAT 3
# define T_DOUBLE 4

class Type
{
	private:
		int		_t;
		char	_c;
		int		_i;
		float	_f;
		double	_d;

	public:
		/* ****************************************************************** */
		/* CONSTRUCTOR & DESTRUCTOR                                           */
		/* ****************************************************************** */
		Type();
		Type(const std::string s);
		Type(const Type &t);
		~Type();

		/* ****************************************************************** */
		/* GETTER & SETTER                                                    */
		/* ****************************************************************** */
		int		getType(void) const;
		char	getChar(void) const;
		int		getInt(void) const;
		float	getFloat(void) const;
		double	getDouble(void) const;

		/* ****************************************************************** */
		/* OPERATOR OVERLOADING                                               */
		/* ****************************************************************** */
		Type	&operator=(const Type &t);

		/* ****************************************************************** */
		/* MEMBER FUNCTION                                                    */
		/* ****************************************************************** */
		void	fillFromChar(const std::string s);
		void	fillFromInt(const std::string s);
		void	fillFromFloat(const std::string s);
		void	fillFromDouble(const std::string s);
		void	printType(void) const;

		/* ****************************************************************** */
		/* MISCELLANEOUS                                                      */
		/* ****************************************************************** */
		class EmptyArgException : std::exception
		{
			public:
				virtual const char* what() const throw();
		};//!EmptyArgException
		class InvalidConversionException : std::exception
		{
			public:
				virtual const char* what() const throw();
		};//!InvalidConversionException
		class ValueOverflowException : std::exception
		{
			public:
				virtual const char* what() const throw();
		};//!ValueOverflowException

};//!Type
/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */

/* ************************************************************************** */
/* OTHER FUNCTIONS                                                            */
/* ************************************************************************** */
void	printFromDouble(double d);
void	printFromFloat(float f);
void	printFromInt(int i);
void	printFromChar(char c);
int		selectType(const std::string s);

#endif