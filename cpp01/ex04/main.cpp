/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/10 17:56:37 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Switch.hpp"

int main(int argc, char const *argv[])
{
	// if (argc == 3)
	// {
	// 	//show
	// }
	if (argc != 4)// else if (argc != 4)
		std::cout << "incorrect number of arguments" << std::endl;
	else
	{
		Switch s = Switch(argv[1], argv[2], argv[3]);
		s.replacing();
	}
	return (0);
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