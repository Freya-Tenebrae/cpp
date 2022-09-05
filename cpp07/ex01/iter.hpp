/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/05 08:15:40 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <string>
# include <iostream>

template <typename T>
void	iter(T *t, const int size, void (f)(T &t))
{
	for (int i = 0; i < size; i++)
	{
		f(t[i]);
	}
}

template <typename T>
void	show(T &t)
{
	std::cout << "\033[0;32m|\033[0;33m" << t << "\033[0;32m|\033[0m ";
}

#endif