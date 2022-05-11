/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Switch.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/11 10:43:34 by cmaginot         ###   ########.fr       */
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

// https://www.cplusplus.com/reference/fstream/ifstream/
// https://www.cplusplus.com/reference/string/string/

// std::ifstream ifs("file_in")
// std::ofstream ofs("file_out")


// Create a program that takes three parameters in the following order: 
// a filename and two strings, s1 and s2.

// It will open the file <filename> and copies its content into a new file
// <filename>.replace, replacing every occurrence of s1 with s2.

// Using C file manipulation functions is forbidden and will be considered 
// cheating. All the member functions of the class std::string are allowed, 
// except replace. Use them wisely!

// Of course, handle unexpected inputs and errors. You have to create and 
// turn in your own tests to ensure your program works as expected.