/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/27 16:55:10 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <iostream>
# include <list>
# include <vector>

class NotFoundException : std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("\033[0;31mElement not found\033[0m");
		}
};//!OutException

template <typename T>
typename T::const_iterator	easyfind(const T &t, const int value)
{
	typename T::const_iterator itr;
	typename T::const_iterator itrend = t.end(); //add

	for (itr = t.begin(); itr != itrend; ++itr)
    {
        if (*itr == value)
            return (itr);
    }
    throw NotFoundException();
}

#endif
