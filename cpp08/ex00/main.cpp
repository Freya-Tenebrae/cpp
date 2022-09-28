/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/27 16:57:56 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

int main(void)
{
	std::cout << "\033[1;36m-----easyfind tests-----\033[0m" << std::endl;
	std::cout << "\033[1;36mInit all\033[0m" << std::endl;

	std::list<int> l;
	l.push_back(0);
	l.push_back(42);
	l.push_back(-9);
	l.push_back(666);
	l.push_back(6);
	l.push_back(42);
	l.push_back(41537);

	std::vector<int> v;
	v.reserve(7);
	v.push_back(0);
	v.push_back(42);
	v.push_back(-9);
	v.push_back(666);
	v.push_back(6);
	v.push_back(42);
	v.push_back(41537);

	std::cout << "\033[1;36mTest 1 : std::list\033[0m" << std::endl;
	try
	{
		std::cout << "\033[0;32measyfind(42) : ";
		std::list<int>::const_iterator l_1 = easyfind(l, 42);
		std::cout << "\033[0;33mFound " << *l_1 << "\033[0m" << std::endl;
	}
	catch (NotFoundException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\033[0;32measyfind(41537) : ";
		std::list<int>::const_iterator l_2 = easyfind(l, 41537);
		std::cout << "\033[0;33mFound " << *l_2 << "\033[0m" << std::endl;
	}
	catch (NotFoundException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\033[0;32measyfind(-42) : ";
		std::list<int>::const_iterator l_3 = easyfind(l, -42);
		std::cout << "\033[0;33mFound " << *l_3 << "\033[0m" << std::endl;
	}
	catch (NotFoundException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[1;36mTest 2 : std::vector\033[0m" << std::endl;
	try
	{
		std::cout << "\033[0;32measyfind(42) : ";
		std::vector<int>::const_iterator v_1 = easyfind(v, 42);
		std::cout << "\033[0;33mFound " << *v_1 << "\033[0m" << std::endl;
	}
	catch (NotFoundException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\033[0;32measyfind(41537) : ";
		std::vector<int>::const_iterator v_2 = easyfind(v, 41537);
		std::cout << "\033[0;33mFound " << *v_2 << "\033[0m" << std::endl;
	}
	catch (NotFoundException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\033[0;32measyfind(-42) : ";
		std::vector<int>::const_iterator v_3 = easyfind(v, -42);
		std::cout << "\033[0;33mFound " << *v_3 << "\033[0m" << std::endl;
	}
	catch (NotFoundException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\033[1;36mEnd of tests\033[0m" << std::endl;
	return (0);
}