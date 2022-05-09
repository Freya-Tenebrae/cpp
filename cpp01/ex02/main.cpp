/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/09 16:29:53 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR	= &str;
	std::string &stringREF	= str;

	std::cout << "memory address of str         : " << &str << std::endl;
	std::cout << "memory address of stringPTR   : " << &stringPTR << std::endl;
	std::cout << "memory address of stringREF   : " << &stringREF << std::endl;

	std::cout << "value of str                  : " << str << std::endl;
	std::cout << "value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF : " << stringREF << std::endl;
	return (0);
}
