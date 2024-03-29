/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:39:27 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/09 15:12:30 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */
Point::Point():_x(0),
		_y(0)
{

}

Point::Point(const Point &p):_x(p.getx()),
								_y(p.gety())
{

}

Point::Point(float const x, float const y):_x(x),
											_y(y)
{

}

Point::~Point()
{

}

/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */
Fixed const	Point::getx() const
{
	return(_x);
}

Fixed const	Point::gety() const
{
	return(_y);
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */
Point &Point::operator=(const Point &p)
{
	(void)p;
	return (*this);
}

std::ostream	&operator<<(std::ostream &output, const Point &p)
{
	output << "Point : x = " << p.getx() << ", y = " << p.gety();
	return (output);	
}
