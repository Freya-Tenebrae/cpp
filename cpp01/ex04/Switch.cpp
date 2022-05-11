/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Switch.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/11 10:55:42 by cmaginot         ###   ########.fr       */
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

 bool Switch::fill_buffer(std::string *buffer)
{
	std::ifstream	ifs(_filename);
	std::string		line;

	if (ifs.is_open())
	{
		while(std::getline(ifs, line))
		{
			*buffer = *buffer + line;
			if (ifs.eof() == false)
				*buffer = *buffer + "\n";
		}
		ifs.close();
		return (true);
	}
	else
	{
		std::cout << _filename << " can't be opened..." << std::endl;
		return (false);
	}
}

void	Switch::switching(std::string *buffer)
{
	size_t	pos;

	pos = (*buffer).find(_strToReplace);
	while (pos != std::string::npos)
	{
		(*buffer).erase(pos, _strToReplace.size());
		(*buffer).insert(pos, _strReplacing);
		pos = (*buffer).find(_strToReplace);
	}
}

void	Switch::createNew_file(std::string buffer)
{
	std::ofstream	ofs("new_" + _filename);
	if (ofs.is_open())
	{
		ofs << buffer;
		ofs.close();
	}
	else
		std::cout << _filename << " can't be created or opened..." << std::endl;
}

void Switch::replacing()
{
	std::string		buffer;

	if (this->fill_buffer(&buffer) == true)
	{
		this->switching(&buffer);
		this->createNew_file(buffer);
	}
}
