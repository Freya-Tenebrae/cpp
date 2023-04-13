/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2023/04/13 13:47:57 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

int main(int argc, char const **argv)
{
	std::cout << "\033[1;36m-----RPN-----\033[0m" << std::endl;
	std::cout << std::endl;

	if (argc != 2)
	{
		std::cerr << "\033[0;31mError: Number of arguments invalid.\033[0m";
		std::cerr << std::endl;
		return (-1);
	}

	try
	{
		RPN rpn;
		std::string str = argv[1], sub;
		std::cout << std::endl;

		while (str.size() != 0)
		{
			size_t pos = str.find(' ');
			sub = str.substr(0, pos);
			if (pos != npos)
			{
				sub = str.substr(0, pos);
				rpn.add_element(sub);
				str.erase(0, pos + 1);
			}
			else
			{
				rpn.add_element(str);
				str.erase();
			}
		}

		std::cout << std::endl;
		std::cout << "\033[0;32mresult : \033[0;33m" << rpn.get_result();
		std::cout << "\033[0m" << std::endl;
		std::cout << std::endl;
	}
	catch (RPN::InvalidElementException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (RPN::DivisionByZeroException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[1;36m-----End of RPN-----\033[0m" << std::endl;
	std::cout << std::endl;

	return (0);
}