/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Type.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:31:11 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/02 17:16:36 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Type.hpp"

/* ************************************************************************** */
/* CONSTRUCTOR & DESTRUCTOR                                                   */
/* ************************************************************************** */
Type::Type()
{
	_t = 0;
	_c = 0;
	_i = 0;
	_f = 0;
	_d = 0;
	std::cout << "\033[0;35mA type is created (default)\033[0m" << std::endl;
}

Type::Type(const std::string s)
{
	_t = selectType(s);
	if (_t == T_CHAR)
		fillFromChar(s);
	else if (_t == T_INT)
		fillFromInt(s);
	else if (_t == T_FLOAT)
		fillFromFloat(s);
	else if (_t == T_DOUBLE)
		fillFromDouble(s);
	std::cout << "\033[0;35mA type is created\033[0m" << std::endl;
}

Type::Type(const Type &t)
{
	*this = t;
	std::cout << "\033[0;35mA type is copied\033[0m" << std::endl;
}

Type::~Type()
{
	std::cout << "\033[0;35mA type is destoyed\033[0m" << std::endl;
}


/* ************************************************************************** */
/* GETTER & SETTER                                                            */
/* ************************************************************************** */
int	Type::getType(void) const
{
	return (this->_t);
}

char	Type::getChar(void) const
{
	return (this->_c);
}

int	Type::getInt(void) const
{
	return (this->_i);
}

float	Type::getFloat(void) const
{
	return (this->_f);
}

double	Type::getDouble(void) const
{
	return (this->_d);
}


/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */
Type	&Type::operator=(const Type &t)
{
	_t = t.getType();
	_c = t.getChar();
	_i = t.getInt();
	_f = t.getFloat();
	_d = t.getDouble();
	return (*this);
}

/* ************************************************************************** */
/* MEMBER FUNCTION                                                            */
/* ************************************************************************** */
void	Type::fillFromChar(const std::string s)
{
	_c = static_cast<char>(s[0]);
	_i = 0;
	_f = 0;
	_d = 0;
}

void	Type::fillFromInt(const std::string s)
{
	long l;

	std::istringstream(s) >> l;
	if (l < static_cast<long>(std::numeric_limits<int>::min()) || \
		l > static_cast<long>(std::numeric_limits<int>::max()))
		throw Type::ValueOverflowException();
	_i = static_cast<int>(l);
	_c = 0;
	_f = 0;
	_d = 0;
}

void	Type::fillFromFloat(const std::string s)
{
	if (s.compare("+inff") == 0)
		_f = std::numeric_limits<float>::infinity();
	else if (s.compare("-inff") == 0)
		_f = -std::numeric_limits<float>::infinity();
	else if (s.compare("nanf") == 0)
		_f = std::numeric_limits<float>::quiet_NaN();
	else
		std::istringstream(s) >> _f;
	_c = 0;
	_i = 0;
	_d = 0;
}

void	Type::fillFromDouble(const std::string s)
{
	if (s.compare("+inf") == 0)
		_d = std::numeric_limits<double>::infinity();
	else if (s.compare("-inf") == 0)
		_d = -std::numeric_limits<double>::infinity();
	else if (s.compare("nan") == 0)
		_d = std::numeric_limits<double>::quiet_NaN();
	else
		std::istringstream(s) >> _d;
	_c = 0;
	_i = 0;
	_f = 0;
}

void	Type::printType(void) const
{
	std::cout << "\033[0;36mtype :\033[0;33m ";
	if (_t == T_CHAR)
	{
		std::cout << "char\033[0m" << std::endl;
		printFromChar(_c);
	}
	if (_t == T_INT)
	{
		std::cout << "int\033[0m" << std::endl;
		printFromInt(_i);
	}
	if (_t == T_FLOAT)
	{
		std::cout << "float\033[0m" << std::endl;
		printFromFloat(_f);
	}
	if (_t == T_DOUBLE)
	{
		std::cout << "double\033[0m" << std::endl;
		printFromDouble(_d);
	}
}

/* ************************************************************************** */
/* MISCELLANEOUS                                                              */
/* ************************************************************************** */
const char* Type::EmptyArgException::what() const throw()
{
	return ("\033[0;31mError :\nThe argument is empty\033[0m");
}

const char* Type::InvalidConversionException::what() const throw()
{
	return ("\033[0;31mError :\nInvalid Argument\033[0m");
}

const char* Type::ValueOverflowException::what() const throw()
{
	return ("\033[0;31mError :\nValue of argument overflow\033[0m");
}
