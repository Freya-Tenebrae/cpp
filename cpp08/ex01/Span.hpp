/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:02:17 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/28 21:26:16 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

/* ************************************************************************** */
/* INCLUDE                                                                    */
/* ************************************************************************** */
# include <string>
# include <iostream>
# include <vector>
# include <algorithm>
# include <ctime>

class Span
{
	private:
		const unsigned int	_n;
		std::vector<int>	_v;

		/* ****************************************************************** */
		/* CONSTRUCTOR & DESTRUCTOR                                           */
		/* ****************************************************************** */
		Span();

	public:
		/* ****************************************************************** */
		/* CONSTRUCTOR & DESTRUCTOR                                           */
		/* ****************************************************************** */
		Span(unsigned int n);
		Span(const Span &s);
		~Span();
		/* ****************************************************************** */
		/* GETTER & SETTER                                                    */
		/* ****************************************************************** */
		unsigned int		getN() const;
		std::vector<int>	getV() const;
		/* ****************************************************************** */
		/* OPERATOR OVERLOADING                                               */
		/* ****************************************************************** */
		Span				&operator=(const Span &s);

		/* ****************************************************************** */
		/* MEMBER FUNCTION                                                    */
		/* ****************************************************************** */
		void				addNumber(int i);
		void				fillWithRandom();
		int					shortestSpan() const;
		int					longestSpan() const;

		/* ****************************************************************** */
		/* MISCELLANEOUS                                                      */
		/* ****************************************************************** */
		class TooFewNumberException : std::exception
		{
			public:
				virtual const char* what() const throw();
		};//!TooFewNumberException
		class SpanFullException : std::exception
		{
			public:
				virtual const char* what() const throw();
		};//!SpanFullException
};//!Span
/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */
std::ostream	&operator<<(std::ostream &output, const Span &s);

#endif
