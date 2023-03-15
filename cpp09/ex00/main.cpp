/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/15 17:55:24 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

static void	test_of_BitcoinExchange(BitcoinExchange &bte)
{
	std::cout << "\033[0;36mdate_invalid month (2020-00-05)\033[0m" << std::endl;
	try
	{
		std::cout << bte.get_real_value("2020-00-05",4.2) << std::endl;
	}
	catch (BitcoinExchange::DateInvalidException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[0;36mdate_invalid day (2020-11-00)\033[0m" << std::endl;
	try
	{
		std::cout << bte.get_real_value("2020-11-00",4.2) << std::endl;
	}
	catch (BitcoinExchange::DateInvalidException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[0;36mdate_before_first_date (1996-11-03)\033[0m" << std::endl;
	try
	{
		std::cout << bte.get_real_value("1996-11-03",4.2) << std::endl;
	}
	catch (BitcoinExchange::DateInvalidException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[0;36mdate_beetween_two_dates (2020-09-03)\033[0m" << std::endl;
	try
	{
		std::cout << bte.get_real_value("2020-09-03",4.2) << std::endl;
	}
	catch (BitcoinExchange::DateInvalidException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[0;36mdate_on_date (2020-09-05)\033[0m" << std::endl;
	try
	{
		std::cout << bte.get_real_value("2020-09-05",4.2) << std::endl;
	}
	catch (BitcoinExchange::DateInvalidException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[0;36mdate_after_last_date (2024-04-01)\033[0m" << std::endl;
	try
	{
		std::cout << bte.get_real_value("2024-04-01",4.2) << std::endl;
	}
	catch (BitcoinExchange::DateInvalidException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void	convert_line(std::string &line, BitcoinExchange &bte)
{
	if (line.find('|', 0) == npos)
	{
		std::cerr << "\033[0;31mError: bad input\033[0m => \033[0;32m";
		std::cerr << line << "\033[0m" << std::endl;
		return ;
	}

	std::string date = line.substr(0, line.find('|', 0) - 1);
	std::string quantity_str = line.substr(line.find('|', 0) + 2);

	std::stringstream strstr;
	strstr << quantity_str;
	long double quantity_value, real_value;
	strstr >> quantity_value;

	if (quantity_value < 0)
		std::cerr << "\033[0;31mError: not a positive number.\033[0m" << std::endl;
	else if (quantity_value > 10000) // value to fix
		std::cerr << "\033[0;31mError: number too large.\033[0m" << std::endl;
	else
	{
		try
		{
			real_value = bte.get_real_value(date, quantity_value);
			std::cout << "\033[0;32m" << date << "\033[0m";
			std::cout << " => \033[0;32m" << quantity_value << "\033[0m = ";
			std::cout << "\033[0;33m" << real_value << "\033[0m" << std::endl;
		}
		catch (BitcoinExchange::DateInvalidException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}



int main(int argc, char ** argv)
{
	std::cout << "\033[1;36m-----btc tests-----\033[0m" << std::endl;
	std::cout << std::endl;

	if (argc != 2)
	{
		std::cerr << "\033[0;31mError: wrong numbers of argument, need one file.\033[0m" << std::endl;
		return (-1);
	}
	try
	{
		std::cout << "\033[1;36mInit BitcoinExchange\033[0m" << std::endl;
		BitcoinExchange bte;
		std::cout << std::endl;

		std::cout << "\033[1;36mTests of BitcoinExchange\033[0m" << std::endl;
		test_of_BitcoinExchange(bte);
		std::cout << std::endl;

		std::cout << "\033[1;36mTest with file\033[0m" << std::endl;
		std::ifstream input(argv[1]);
		std::string line;
		if (!std::getline(input, line) || line.compare("") == 0)
			std::cerr << "\033[0;31mError: cannot load file.\033[0m" << std::endl;

		while(std::getline(input, line))
			convert_line(line, bte);
		std::cout << std::endl;

		std::cout << "\033[1;36mDestroy BitcoinExchange\033[0m" << std::endl;
	}
	catch (BitcoinExchange::ParsingErrorException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[1;36m-----End of tests-----\033[0m" << std::endl;
	return (0);
}