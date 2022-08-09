/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:21 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/09 14:20:56 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact			_contact_list[8];
		int				_n_contact;

	public:
		PhoneBook();
		~PhoneBook();

		void			add();
		void			search();
};//!PhoneBook

#endif