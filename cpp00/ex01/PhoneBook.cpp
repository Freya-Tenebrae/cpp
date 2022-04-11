/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:21 by cmaginot          #+#    #+#             */
/*   Updated: 2022/04/12 00:42:06 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	display_info_table(std::string content)
{
	if (content.size() > 10)
	{
		std::cout << std::max(9) << content;
		std::cout << ".";
	}
	else
		std::cout << std::setw(10) << content;
}

static void	display_info(Contact c)
{
	std::cout << "First Name : ";
	std::cout << c.get_first_name() << std::endl;
	std::cout << "Last Name : ";
	std::cout << c.get_last_name() << std::endl;
	std::cout << "Nickname : ";
	std::cout << c.get_nickname() << std::endl;
	std::cout << "Phone Number: ";
	std::cout << c.get_phone_number() << std::endl;
	std::cout << "Dark And Deepest Secret : ";
	std::cout << c.get_darkest_secret() << std::endl;
}

PhoneBook::PhoneBook():_n_contact(0)
{
	//nothing
}

PhoneBook::~PhoneBook()
{
	std::cout << "All contact have been forever lost ..." << std::endl;
}

void	PhoneBook::add()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	std::cout << "contact n* : " << this->_n_contact << std::endl;
	std::cout << "Enter your first name : ";
	getline(std::cin, first_name);
	std::cout << "Enter your last name : ";
	getline(std::cin, last_name);
	std::cout << "Enter your nickname : ";
	getline(std::cin, nickname);
	std::cout << "Enter your phone number : ";
	getline(std::cin, phone_number);
	std::cout << "Enter your dark and deepest secret : ";
	getline(std::cin, darkest_secret);
	this->_contact_list[this->_n_contact++ % 8] = Contact( \
		first_name, last_name, nickname, phone_number, darkest_secret);
}

void	PhoneBook::search()
{
	int			i;
	std::string	index;
	i = 0;
	std::cout << "/-------------------------------------------\\" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (i++ < this->_n_contact)
	{
		std::cout << "|         " << i - 1 << "|";
		display_info_table(this->_contact_list[i - 1].get_first_name());
		std::cout << "|";
		display_info_table(this->_contact_list[i - 1].get_last_name());
		std::cout << "|";
		display_info_table(this->_contact_list[i - 1].get_nickname());
		std::cout << "|" <<std::endl;
	}
	std::cout << "\\-------------------------------------------/" << std::endl;
	if (this->_n_contact == 0)
		std::cout << "No contact in this PhoneBook" << std::endl;
	else
	{
		std::cout << "Enter the index of the contact : ";
		getline(std::cin, index);
		std::istringstream(index) >> i;
		if (i < this->_n_contact)
			display_info(this->_contact_list[i]);
		else
			std::cout << "This contact didn't exist" << std::endl;
	}
}

