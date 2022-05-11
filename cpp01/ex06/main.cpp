/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/11 20:53:09 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static void	totalyFiltered()
{
	std::cout << "\033[44[ Probably complaining about insignificant problems ]" << std::endl;
}

static void	harlFilter(std::string const filter)
{
	Harl h = Harl();
	switch(filter)
	{
		case "DEBUG":
			h.complain("DEBUG");
		case "INFO":
			h.complain("INFO");
		case "WARNING":
			h.complain("WARNING");
		case "ERROR":
			h.complain("ERROR");
			break;
		default:
			std::cout << "\033[44[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
		totalyFiltered();
	else
`		harlFilter(argv[1]);
	return (0);
}
