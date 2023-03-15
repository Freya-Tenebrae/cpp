/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/15 17:55:30 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <cstring>
# include <sstream>
# include <iomanip>

static const size_t npos = -1;

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_data;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &bte);
		~BitcoinExchange();

		BitcoinExchange					&operator=(const BitcoinExchange &bte);

		double							get_real_value(std::string, double quantity_value);

		class ParsingErrorException : std::exception
		{
			public:
				virtual const char* what() const throw();
		};//!ParsingErrorException
		class DateInvalidException : std::exception
		{
			public:
				virtual const char* what() const throw();
		};//!DateInvalidException

};//!BitcoinExchange


#endif
