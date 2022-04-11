/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:21 by cmaginot          #+#    #+#             */
/*   Updated: 2022/04/11 22:51:38 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	//nothing
}

Contact::Contact(std::string first_name, std::string last_name, \
					std::string nickname, std::string phone_number , \
					std::string darkest_secret):
					_first_name(first_name),
					_last_name(last_name),
					_nickname(nickname),
					_phone_number(phone_number),
					_darkest_secret(darkest_secret)
{
	//nothing
}

Contact::~Contact()
{
	//nothing
}

std::string	Contact::get_first_name()
{
	return (this->_first_name);
}

std::string	Contact::get_last_name()
{
	return (this->_last_name);
}

std::string	Contact::get_nickname()
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number()
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret()
{
	return (this->_darkest_secret);
}
