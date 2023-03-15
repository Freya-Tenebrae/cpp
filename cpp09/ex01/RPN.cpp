/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/15 19:19:16 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "\033[0;35mRPN is created\033[0m" << std::endl;
}

RPN::RPN(const RPN &rpn)
{
	std::cout << "\033[0;35mRPN is duplicated\033[0m" << std::endl;
	*this = rpn;
}

RPN::~RPN()
{
	std::cout << "\033[0;35mRPN is destroyed\033[0m" << std::endl;
}

RPN	&RPN::operator=(const RPN &rpn)
{
	(void)rpn;
	return *this;
}

void	RPN::add()
{
	int value = _st.top();
	_st.pop();
	_st.top() += value;
	std::cout << "\033[0;34madd\033[0m" << std::endl;
}

void	RPN::substract()
{
	int value = _st.top();
	_st.pop();
	_st.top() -= value;
	std::cout << "\033[0;34msubstract\033[0m" << std::endl;
}

void	RPN::multiply()
{
	int value = _st.top();
	_st.pop();
	_st.top() *= value;
	std::cout << "\033[0;34mmultilpy\033[0m" << std::endl;
}

void	RPN::divide()
{
	int value = _st.top();
	_st.pop();
	_st.top() /= value;
	std::cout << "\033[0;34mdivide\033[0m" << std::endl;
}

void	RPN::add_number(int number)
{
	_st.push(number);
	std::cout << "\033[0;32madd number \033[0;33m" << number << "\033[0;32m on stack\033[0m" << std::endl;
}

void	RPN::add_operation(char oper)
{
	if (oper == '+')
		add();
	else if (oper == '-')
		substract();
	else if (oper == '*')
		multiply();
	else if (oper == '/')
		divide();
	else
		throw InvalidElementException();
}

void	RPN::add_element(std::string element)
{
	std::string valid_operator = VALID_OPERATOR;

	if (element.compare("") == 0)
		throw InvalidElementException();

	if (valid_operator.find(element[0]) != npos)
		add_operation(element[0]);
	else
	{
		for (std::string::iterator it = element.begin(); it != element.end(); it++)
		{
			if (*it >= '0' && *it <= '9')
				;
			else
				throw InvalidElementException();
		}
		std::stringstream strstr;
		strstr << element;
		int number;
		strstr >> number;
		add_number(number);
	}
}

int		RPN::get_result()
{
	return (_st.top());
}

const char* RPN::InvalidElementException::what() const throw()
{
	return ("\033[0;31mError : Element invalid\033[0m");
}