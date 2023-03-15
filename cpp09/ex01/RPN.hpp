/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/15 19:00:58 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define VALID_OPERATOR "+-/*"

# include <stack>
# include <string>
# include <iostream>
# include <fstream>
# include <cstring>
# include <sstream>
# include <iomanip>

static const size_t npos = -1;

class RPN
{
	private:
		std::stack<int>	_st;

		void	add();
		void	substract();
		void	multiply();
		void	divide();
		void	add_number(int number);
		void	add_operation(char oper);

	public:
		RPN();
		RPN(const RPN &rpn);
		~RPN();

		RPN		&operator=(const RPN &rpn);

		void	add_element(std::string element);
		int		get_result();

		class InvalidElementException : std::exception
		{
			public:
				virtual const char* what() const throw();
		};//!DateInvalidException
};//!RPN


#endif
