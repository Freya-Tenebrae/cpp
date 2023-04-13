/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2023/04/04 18:02:58 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

static bool check_if_valid(int argc, char const **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string value = argv[i];
		if (value.size() == 0 || value[0] == '-')
		{
			std::cerr << "\033[0;31mError: This program only work with positif integer.\033[0m";
			std::cerr << std::endl;
			return (false);
		}

		for (std::string::iterator it = value.begin(); it != value.end(); it++)
		{
			if (!(*it >= '0' && *it <= '9'))
			{
				std::cerr << "\033[0;31mError: This program only work with positif integer.\033[0m";
				std::cerr << std::endl;
				return (false);
			}
		}
	}
	return (true);
}

int main(int argc, char const **argv)
{
	std::cout << "\033[1;36m-----PmergeMe-----\033[0m" << std::endl;
	std::cout << std::endl;

	PmergeMe *pm = new PmergeMe();
	std::cout << std::endl;

	if (argc > 1)
	{
		if (check_if_valid(argc, argv) == true)
		{
			for (int i = 1; i < argc; i++)
			{
				std::string value;
				std::stringstream strstr;
				int int_value;

				value = argv[i];
				strstr << value;
				strstr >> int_value;
			
				pm->add_value(int_value);
			}
			
			pm->sort();
		}
		std::cout << std::endl;
	}
	else
	{
		std::cerr << "\033[0;31mError: This program need arguments to work.\033[0m";
		std::cerr << std::endl << std::endl;
	}

	delete pm;

	std::cout << std::endl;
	std::cout << "\033[1;36m-----End of PmergeMe-----\033[0m" << std::endl;

	return (0);
}