/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/06 15:59:34 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

int main(void)
{
	std::cout << "\033[1;36m-----easyfind tests-----\033[0m" << std::endl;
	std::cout << "\033[1;36mTest 1 : std::list\033[0m" << std::endl;
	std::list<int> l;
	l.push_back(0);
	l.push_back(42);
	l.push_back(-9);
	l.push_back(666);
	l.push_back(6);
	l.push_back(42);
	l.push_back(41537);
	try
	{
		std::cout << "\033[0;32measyfind(42) : ";
		std::_List_iterator<int> l_1 = easyfind(l, 42);
		std::cout << "\033[0;33mFound\033[0m" << std::endl;
		(void)l_1;
	}
	catch (NotFoundException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\033[0;32measyfind(41537) : ";
		std::_List_iterator<int> l_2 = easyfind(l, 41537);
		std::cout << "\033[0;33mFound\033[0m" << std::endl;
		(void)l_2;
	}
	catch (NotFoundException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\033[0;32measyfind(-42) : ";
		std::_List_iterator<int> l_3 = easyfind(l, -42);
		std::cout << "\033[0;33mFound\033[0m" << std::endl;
		(void)l_3;
	}
	catch (NotFoundException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\033[1;36mEnd of tests\033[0m" << std::endl;
	return (0);
}