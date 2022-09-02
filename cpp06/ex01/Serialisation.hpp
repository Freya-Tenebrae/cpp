/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialisation.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:31:13 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/02 17:30:19 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALISATION_HPP
# define SERIALISATION_HPP

/* ************************************************************************** */
/* INCLUDE                                                                     */
/* ************************************************************************** */
# include <string>
# include <iostream>
# include <stdint.h>

/* ************************************************************************** */
/* DEFINE                                                                     */
/* ************************************************************************** */
typedef struct Data
{
	int			data_v1;
	std::string	data_v2;

}				data;

class Serialisation
{
	public:
		/* ****************************************************************** */
		/* CONSTRUCTOR & DESTRUCTOR                                           */
		/* ****************************************************************** */
		Serialisation();
		Serialisation(const Serialisation &s);
		~Serialisation();

		/* ****************************************************************** */
		/* GETTER & SETTER                                                    */
		/* ****************************************************************** */

		/* ****************************************************************** */
		/* OPERATOR OVERLOADING                                               */
		/* ****************************************************************** */
		Serialisation	&operator=(const Serialisation &s);

		/* ****************************************************************** */
		/* MEMBER FUNCTION                                                    */
		/* ****************************************************************** */
		uintptr_t		serialize(Data* ptr);
		Data*			deserialize(uintptr_t raw);

		/* ****************************************************************** */
		/* MISCELLANEOUS                                                      */
		/* ****************************************************************** */
		// class EmptyArgException : std::exception
		// {
		// 	public:
		// 		virtual const char* what() const throw();
		// };//!EmptyArgException
		// class InvalidConversionException : std::exception
		// {
		// 	public:
		// 		virtual const char* what() const throw();
		// };//!InvalidConversionException
		// class ValueOverflowException : std::exception
		// {
		// 	public:
		// 		virtual const char* what() const throw();
		// };//!ValueOverflowException

};//!Serialisation

#endif