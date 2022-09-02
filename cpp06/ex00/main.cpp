/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/01 19:07:12 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Type.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			Type t(static_cast<const std::string>(argv[1]));
			t.printType();
		}
		catch (Type::EmptyArgException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (Type::InvalidConversionException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (Type::ValueOverflowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else if (argc == 1)
	{
		std::cerr << "\033[0;31mError :\nNo argument given\033[0m";
		std::cerr << std::endl;
	}
	else
	{
		std::cerr << "\033[0;31mError :\nToo many arguments given\033[0m";
		std::cerr << std::endl;
	}
	return (0);
}
