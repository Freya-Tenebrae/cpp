/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/15 17:56:06 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream input("data.csv");
	std::string line;

	if (!std::getline(input, line) || line.compare("") == 0)
		throw ParsingErrorException();

	while(std::getline(input, line))
	{
		if (line.find(',', 0) == npos)
			throw ParsingErrorException();

		std::string date = line.substr(0, line.find(',', 0));
		std::string exchange_rate_str = line.substr(line.find(',', 0) + 1);
		std::stringstream strstr;
		strstr << exchange_rate_str;
		long double exchange_rate_value;
		strstr >> exchange_rate_value;

		// std::cout << "|" << date << "|" << exchange_rate_str << "|";
		// std::cout << exchange_rate_value << "|" << std::endl;

		_data.insert(std::pair<std::string, double>(date, exchange_rate_value));
	}
	std::cout << "\033[0;35mBitcoinExchange is created\033[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bte)
{
	*this = bte;
	std::cout << "\033[0;35mBitcoinExchange is duplicated\033[0m" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "\033[0;35mBitcoinExchange is destroyed\033[0m" << std::endl;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &bte)
{
	std::map<std::string, double> data;
	(void)bte;
	return *this;
}

double	BitcoinExchange::get_real_value(std::string date, double quantity_value)
{
	if (date.find("00", 5) != npos || date.compare(_data.begin()->first) < 0)
		throw DateInvalidException();

	for (std::map<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); )
	{
		double value = it->second;
		if (date.compare(it->first) >= 0 && ++it != _data.end() && date.compare(it->first) < 0)
			return (quantity_value * value);
	}
	throw DateInvalidException();
}

const char* BitcoinExchange::ParsingErrorException::what() const throw()
{
	return ("\033[0;31mError on data.csv parsing\033[0m");
}

const char* BitcoinExchange::DateInvalidException::what() const throw()
{
	return ("\033[0;31mError : Date invalid\033[0m");
}
