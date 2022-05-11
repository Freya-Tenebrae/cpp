/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/11 10:01:05 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Switch.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 4)
		std::cout << "incorrect number of arguments" << std::endl;
	else
	{
		Switch s = Switch(argv[1], argv[2], argv[3]);
		s.replacing();
	}
	return (0);
}
