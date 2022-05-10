/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Switch.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/10 18:01:12 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Switch.hpp"

Switch::Switch(std::string const filename, std::string const s1, \
				std::string const s2):	_filename(filename),
										_strToReplace(s1),
										_strReplacing(s2)
														
{
	
}

Switch::~Switch()
{
	
}

void Switch::replacing()
{
	int 				i = 0;
	std::ifstream		ifs(_filename);
	std::ofstream		ofs("new_" + _filename);
	std::string			line;

	while (i != 0)
	{
		ifs >> line;
		std::cout << line << std::endl;
		if (line == "")
			i = 1;
		else
		{
			line = line + "test";
			ofs << "test" << std::endl;
		}
	}
	//test didn't work
}
