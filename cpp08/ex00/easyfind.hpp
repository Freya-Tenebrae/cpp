/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/06 15:54:29 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <iostream>
# include <list>

class NotFoundException : std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("\033[0;31mElement not found\033[0m");
		}
};//!OutException

template <typename T>
typename T::iterator	&easyfind(const T &t, const int value)
{
	typename T::iterator itr;

	itr = std::find(t.begin(), t.end(), value);
	if (itr == t.end())
		throw NotFoundException();
	return (itr);
}

#endif