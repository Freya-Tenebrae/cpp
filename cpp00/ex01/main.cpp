/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:30 by cmaginot          #+#    #+#             */
/*   Updated: 2022/04/11 23:18:40 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook has_been_phonebook;
	std::string cmd;

	std::cout << "Thank you for using HBS : the has been phonebook" << std::endl;
	std::cout << "You can add a contact with the entry 'ADD'" << std::endl;
	std::cout << "You can search a contact with the entry 'SEARCH" << std::endl;
	std::cout << "You can quit the phonebook with the entry 'EXIT" << std::endl;
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