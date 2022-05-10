/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Show.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/10 17:29:33 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Show.hpp"

Show::Show(std::string const filename1, std::string const filename2):
														_filename1(filename1),
														_filename2(filename2)
														
{
	
}

void	Show::show_all_line()
{
	// will show each line of both files with the form below :
	// <file1>:<line_1>
	// <file2>:<line_1>
	// <file1>:<line_2>
	// <file2>:<line_2>
	// ...
	// <file1>:<line_n>
	// <file2>:<line_n>
}

void	Show::show_diff()
{
	// will show each line of both files were both line are not equal with 
	// the form below :
	// <file1>:<line_n1>
	// <file2>:<line_n1>
	// <file1>:<line_n2>
	// <file2>:<line_n2>
	// ...
	// <file1>:<line_nn>
	// <file2>:<line_nn>
}


Show::~Show()
{
	
}
