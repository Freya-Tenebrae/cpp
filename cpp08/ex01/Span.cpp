/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:02:13 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/28 21:26:10 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():_n(0)
{
	std::cout << "\033[0;35mA empty Span is created - Do not use this\033[0m";
	std::cout << std::endl;
}

Span::Span(unsigned int n):_n(n)
{
	_v.reserve(n);
	std::cout << "\033[0;35mA Span is created\033[0m" << std::endl;
}

Span::Span(const Span &s):_n(s.getN())
{
	std::cout << "\033[0;35mA Span is duplicated\033[0m" << std::endl;
	*this = s;
}

Span::~Span()
{
	std::cout << "\033[0;35mA Span is destroyed\033[0m" << std::endl;
}

unsigned int	Span::getN() const
{
	return (_n);
}

std::vector<int>	Span::getV() const
{
	return (_v);
}

Span	&Span::operator=(const Span &s)
{
	this->_v = s.getV();
	return (*this);
}

void	Span::addNumber(int i)
{
	if (_v.size() < _n)
		_v.push_back(i);
	else
		throw SpanFullException();
}

void	Span::fillWithRandom()
{
	static int j;

	if (!j)
		j = 0;
	for (unsigned int i = _v.size(); i < _n; i++)
	{
		std::srand(std::time(0) + i + j++);
		addNumber(std::rand());
	}
}

int	Span::shortestSpan() const
{
	std::vector<int>	v;
	int					minSpan;
	int					lastValue;

	if (_n <= 1 || _v.size() <= 1)
		throw TooFewNumberException();
	v = _v;
	std::sort(v.begin(), v.end());
	minSpan = v[1] - v[0];
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		if (it != v.begin() && minSpan > *it - lastValue)
			minSpan = *it - lastValue;
		lastValue = *it;
	}
	return (minSpan);
}

int	Span::longestSpan() const
{
	if (_n <= 1 || _v.size() <= 1)
		throw TooFewNumberException();

	std::vector<int>::const_iterator min = std::min_element(_v.begin(), _v.end());
	std::vector<int>::const_iterator max = std::max_element(_v.begin(), _v.end());
	return (*max - *min);
}

const char* Span::TooFewNumberException::what() const throw()
{
	return ("\033[0;31mToo few number is present to calcul a span\033[0m");
}

const char* Span::SpanFullException::what() const throw()
{
	return ("\033[0;31mThe span is full, you can't add another number\033[0m");
}

std::ostream	&operator<<(std::ostream &output, const Span &s)
{
	std::vector<int> v = s.getV();
	output << " \033[0;32msize  : \033[0;33m" << s.getN() << std::endl;
	output << "      \033[0;32mvalue : {\033[0;33m";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    	output << *it << "\033[0;32m,\033[0;33m ";
    if (v.size() != 0)
    	output << "\b\b" ;
    output << "\033[0;32m}\033[0m";
	output << std::endl;
	return (output);
}
