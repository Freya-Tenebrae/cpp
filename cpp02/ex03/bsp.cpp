/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:39:27 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/17 14:30:18 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float sign(Point const point, Point const a, Point const b)
{
	float f1, f2, f3, f4;
	// std::cout << "(" << point.getx().toFloat() << " - " << b.getx().toFloat();
	// std::cout << ") * (" << a.gety().toFloat() << " - " << b.gety().toFloat();
	// std::cout << ") - (" << a.getx().toFloat() << " - " << b.getx().toFloat();
	// std::cout << ") * (" << point.gety().toFloat() << " - ";
	// std::cout << b.gety().toFloat() << ")";
	// std::cout << std::endl;
	f1 = point.getx().toFloat() - b.getx().toFloat();
	f2 = a.gety().toFloat() - b.gety().toFloat();
	f3 = a.getx().toFloat() - b.getx().toFloat();
	f4 = point.gety().toFloat() - b.gety().toFloat();

	return ((f1 * f2) - (f3 * f4));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float d1, d2, d3;
	// std::cout << std::endl;
	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);
	// std::cout << "d1 = " << d1 << std::endl;
	// std::cout << "d2 = " << d2 << std::endl;
	// std::cout << "d3 = " << d3 << std::endl;
	if (d1 == 0 || d2 == 0 || d3 == 0)
		return (false);
	return !((d1 < 0 || d2 < 0 || d3 < 0) && (d1 > 0 || d2 > 0 || d3 > 0));
}
