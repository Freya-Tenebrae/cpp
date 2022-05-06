/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:30 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/06 14:57:37 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook has_been_phonebook;
	std::string cmd;

	cmd = "";
	while (cmd.compare("EXIT") != 0)
	{
		std::cout << "HBS~>";
		getline(std::cin, cmd);
		if (cmd.compare("ADD") == 0)
			has_been_phonebook.add();
		else if (cmd.compare("SEARCH") == 0)
			has_been_phonebook.search();
	}
	return (0);
}