/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printFromType.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:31:11 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/02 16:58:04 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Type.hpp"

/* ************************************************************************** */
/* STATIC FUNCTION                                                            */
/* ************************************************************************** */
void	printFromDouble(double d)
{
	std::cout << "\033[0;36mChar :\033[0;33m ";
	if (d < 0.0 || d > 127.0 || std::isnan(d))
		std::cout << "Impossible\033[0m" << std::endl;
	else if (d < 32.0 || d > 126.0)
		std::cout << "Non displayable\033[0m" << std::endl;
	else
		std::cout << static_cast<char>(d) << "\033[0m" << std::endl;
	std::cout << "\033[0;36mInt :\033[0;33m ";
	if (d >= static_cast<double>(std::numeric_limits<int>::min()) && \
		d <= static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << static_cast<int>(d) << "\033[0m" << std::endl;
	else
		std::cout << "Impossible\033[0m" << std::endl;
	std::cout << "\033[0;36mFloat :\033[0;33m ";
	if (std::isnan(d) || std::isinf(d))
		std::cout << static_cast<float>(d) << "f\033[0m" << std::endl;
	else
		std::cout << static_cast<float>(d) << "\033[0m" << std::endl;
	std::cout << "\033[0;36mDouble :\033[0;33m ";
	std::cout << d << "\033[0m" << std::endl;
}

void	printFromFloat(float f)
{
	std::cout << "\033[0;36mChar :\033[0;33m ";
	if (f < 0.0f || f > 127.0f || std::isnan(f))
		std::cout << "Impossible\033[0m" << std::endl;
	else if (f < 32.0f || f > 126.0f)
		std::cout << "Non displayable\033[0m" << std::endl;
	else
		std::cout << static_cast<char>(f) << "\033[0m" << std::endl;
	std::cout << "\033[0;36mInt :\033[0;33m ";
	if (f >= static_cast<float>(std::numeric_limits<int>::min()) && \
		f <= static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << static_cast<int>(f) << "\033[0m" << std::endl;
	else
		std::cout << "Impossible\033[0m" << std::endl;
	std::cout << "\033[0;36mFloat :\033[0;33m ";
	if (std::isnan(f) || std::isinf(f))
		std::cout << f << "f\033[0m" << std::endl;
	else
		std::cout << f << "\033[0m" << std::endl;
	std::cout << "\033[0;36mDouble :\033[0;33m ";
	std::cout << static_cast<double>(f) << "\033[0m" << std::endl;
}

void	printFromInt(int i)
{
	std::cout << "\033[0;36mChar :\033[0;33m ";
	if (i < 0 || i > 127)
		std::cout << "Impossible\033[0m" << std::endl;
	else if (i < 32 || i > 126)
		std::cout << "Non displayable\033[0m" << std::endl;
	else
		std::cout << static_cast<char>(i) << "\033[0m" << std::endl;
	std::cout << "\033[0;36mInt :\033[0;33m ";
	std::cout << i << "\033[0m" << std::endl;
	std::cout << "\033[0;36mFloat :\033[0;33m ";
	std::cout << static_cast<float>(i) << "\033[0m" << std::endl;
	std::cout << "\033[0;36mDouble :\033[0;33m ";
	std::cout << static_cast<double>(i) << "\033[0m" << std::endl;
}

void	printFromChar(char c)
{
	std::cout << "\033[0;36mChar :\033[0;33m ";
	std::cout << c << "\033[0m" << std::endl;
	std::cout << "\033[0;36mInt :\033[0;33m ";
	std::cout << static_cast<int>(c) << "\033[0m" << std::endl;
	std::cout << "\033[0;36mFloat :\033[0;33m ";
	std::cout << static_cast<float>(c) << "\033[0m" << std::endl;
	std::cout << "\033[0;36mDouble :\033[0;33m ";
	std::cout << static_cast<double>(c) << "\033[0m" << std::endl;
}
