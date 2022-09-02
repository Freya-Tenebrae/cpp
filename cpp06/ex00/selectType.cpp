/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:45:37 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/02 16:58:16 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Type.hpp"

static int	isDouble(const std::string s)
{
	int i;
	int nDot;

	if (s.compare("-inf") == 0 || s.compare("+inf") == 0 || \
		s.compare("nan") == 0)
		return(0);
	i = -1;
	nDot = 0;
	while (s[++i] != '\0')
	{
		if (i == 0)
		{
			if ((s[i] == '-' || s[i] == '+') && s[i + 1] == '\0')
				return (-1);
			else if (s[i] != '-' && s[i] != '+' && (s[i] < '0' || s[i] > '9'))
				return (-1);
		}
		else if (s[i] == '.')
		{
			if (s[i - 1] == '+' || s[i - 1] == '-' || s[i + 1] == '\0')
				return (-1);
			nDot++;
		}
		else if ((s[i] < '0' || s[i] > '9'))
			return (-1);
		if (nDot > 1)
			return (-1);
	}
	if (nDot == 0)
		return (-1);
	return (0);
}

static int	isFloat(const std::string s)
{
	int i;
	int nDot;
	int fIsHere;

	if (s.compare("-inff") == 0 || s.compare("+inff") == 0 || \
		s.compare("nanf") == 0)
		return(0);
	i = -1;
	nDot = 0;
	fIsHere = 0;
	while (s[++i] != '\0')
	{
		if (i == 0)
		{
			if ((s[i] == '-' || s[i] == '+') && s[i + 1] == '\0')
				return (-1);
			else if (s[i] != '-' && s[i] != '+' && (s[i] < '0' || s[i] > '9'))
				return (-1);
		}
		else if (s[i] == '.')
		{
			if (s[i - 1] == '+' || s[i - 1] == '-' || s[i + 1] == '\0')
				return (-1);
			nDot++;
		}
		else if (s[i] == 'f')
		{
			if (s[i - 1] == '+' || s[i - 1] == '-'|| s[i - 1] == '.' || \
															s[i + 1] != '\0')
				return (-1);
			fIsHere = 1;
		}
		else if ((s[i] < '0' || s[i] > '9'))
			return (-1);
		if (nDot > 1)
			return (-1);
	}
	if (fIsHere == 0 || nDot == 0)
		return (-1);
	return (0);
}

static int	isInt(const std::string s)
{
	int i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (i == 0)
		{
			if (s[i] == '-' && s[i + 1] == '\0')
				return (-1);
			else if (s[i] != '-' && (s[i] < '0' || s[i] > '9'))
				return (-1);
		}
		else if ((s[i] < '0' || s[i] > '9'))
			return (-1);
	}
	return (0);
}

static int	isChar(const std::string s)
{
	if (s[1] == '\0')
		return (0);
	else
		return (-1);
	return (-1);
}

int	selectType(const std::string s)
{
	if (s[0] == '\0')
		throw Type::EmptyArgException();
	if (isInt(s) == 0)
		return (T_INT);
	else if (isDouble(s) == 0)
		return (T_DOUBLE);
	else if (isFloat(s) == 0)
		return (T_FLOAT);
	else if (isChar(s) == 0)
		return (T_CHAR);
	throw Type::InvalidConversionException();
}