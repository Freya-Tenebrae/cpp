/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/09 14:57:07 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( Fixed(5.05f) * Fixed(2) );
	Fixed c(42.75f);
	Fixed d(10);
	Fixed e = c;
	Fixed const f(42.42f);
	Fixed const g(72.5f);

	std::cout << "\033[1;36mVariables :\033[0m" << std::endl;
	std::cout << "a        : " << a << std::endl;
	std::cout << "b        : " << b << std::endl;
	std::cout << "c        : " << c << std::endl;
	std::cout << "d        : " << d << std::endl;
	std::cout << "e        : " << e << std::endl;
	std::cout << "f        : " << f << std::endl;
	std::cout << "g        : " << g << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;36mMendatory tests :\033[0m" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;36mComparison operator tests :\033[0m" << std::endl;
	std::cout << "c < d    : " << (c < d) << std::endl;
	std::cout << "c < e    : " << (c < e) << std::endl;
	std::cout << "c <= d   : " << (c <= d) << std::endl;
	std::cout << "c <= e   : " << (c <= e) << std::endl;
	std::cout << "c > d    : " << (c > d) << std::endl;
	std::cout << "c > e    : " << (c > e) << std::endl;
	std::cout << "c >= d   : " << (c >= d) << std::endl;
	std::cout << "c >= e   : " << (c >= e) << std::endl;
	std::cout << "c == d   : " << (c == d) << std::endl;
	std::cout << "c == e   : " << (c == e) << std::endl;
	std::cout << "c != d   : " << (c != d) << std::endl;
	std::cout << "c != e   : " << (c != e) << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;36mArithmetic operator tests :\033[0m" << std::endl;
	std::cout << "c + d    : " << (c + d) << std::endl;
	std::cout << "c + e    : " << (c + e) << std::endl;
	std::cout << "c - d    : " << (c - d) << std::endl;
	std::cout << "c - e    : " << (c - e) << std::endl;
	std::cout << "c * d    : " << (c * d) << std::endl;
	std::cout << "c * e    : " << (c * e) << std::endl;
	std::cout << "c / d    : " << (c / d) << std::endl;
	std::cout << "c / e    : " << (c / e) << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;36mIncremetation operator tests :\033[0m" << std::endl;
	std::cout << "c++      : " << c++ << "   --> " << c << std::endl;
	std::cout << "d++      : " << d++ << "      --> " << d << std::endl;
	std::cout << "++c      : " << ++c << " --> " << c << std::endl;
	std::cout << "++d      : " << ++d << " --> " << d << std::endl;
	std::cout << "c--      : " << c-- << " --> " << c << std::endl;
	std::cout << "d--      : " << d-- << " --> " << d << std::endl;
	std::cout << "--c      : " << --c << "   --> " << c << std::endl;
	std::cout << "--d      : " << --d << "      --> " << d << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;36mMax and Min function tests :\033[0m" << std::endl;
	std::cout << "max(c,d) : " << Fixed::max(c, d) << std::endl;
	std::cout << "max(c,e) : " << Fixed::max(c, e) << std::endl;
	std::cout << "max(f,g) : " << Fixed::max(f, g) << std::endl;
	std::cout << "max(c,g) : " << Fixed::max(c, g) << std::endl;
	std::cout << "min(c,d) : " << Fixed::min(c, d) << std::endl;
	std::cout << "min(c,e) : " << Fixed::min(c, e) << std::endl;
	std::cout << "min(f,g) : " << Fixed::min(f, g) << std::endl;
	std::cout << "min(c,g) : " << Fixed::min(c, g) << std::endl;


	return (0);
}
