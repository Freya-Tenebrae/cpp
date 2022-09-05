/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/05 09:50:36 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <string>
# include <iostream>

template <typename T>
class Array
{
	private:
		T				*_t;
		unsigned int	_size;

	public:
		/* ****************************************************************** */
		/* CONSTRUCTOR & DESTRUCTOR                                           */
		/* ****************************************************************** */
		Array<T>()
		{
			std::cout << "\033[0;35mConstruction of empty T_Array\033[0m";
			std::cout << std::endl;
			_size = 0;
			_t = new T[0]; 
		}
		Array<T>(unsigned int n)
		{
			std::cout << "\033[0;35mConstruction of T_Array (size ";
			std::cout << n << ")\033[0m" << std::endl;

			T	*default_value = new T();

			_size = n;
			_t = new T[n];
			for (unsigned int i = 0; i < n; i++)
				_t[i] = *default_value;
			delete (default_value);
		}
		Array<T>(Array<T> const &a)
		{
			std::cout << "\033[0;35mCopy of T_Array\033[0m" << std::endl;
			*this = a;
		}
		~Array<T>()
		{
			std::cout << "\033[0;35mDestruction of T_Array\033[0m";
			std::cout << std::endl;
			// for int ()
			delete []_t;
		}

		/* ****************************************************************** */
		/* GETTER & SETTER                                                    */
		/* ****************************************************************** */
		unsigned int	getSize(void) const
		{
			return (_size);
		}
		T					*getTab(void) const
		{
			return (_t);
		}
		T					getValue(unsigned int i) const
		{
			if (i >= _size)
				throw OutException();
			return (_t[i]);
		}

		/* ****************************************************************** */
		/* OPERATOR OVERLOADING                                               */
		/* ****************************************************************** */
		Array<T>			&operator=(const Array<T> &a)
		{
			_size = a.getSize();
			_t = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_t[i] = a.getValue(i);
			return (*this);
		}
		T					&operator[](unsigned int i)
		{
			if (i >= _size)
				throw OutException();
			return (_t[i]);
		}

		/* ****************************************************************** */
		/* MEMBER FUNCTION                                                    */
		/* ****************************************************************** */
		unsigned int		size(void) const
		{
			return (getSize());
		}
		void				show(void) const
		{
			for (unsigned int i = 0; i < _size; i++)
				std::cout << "\033[0;32m|\033[0;33m" << _t[i] << "\033[0;32m|\033[0m ";
		}

		/* ****************************************************************** */
		/* MISCELLANEOUS                                                      */
		/* ****************************************************************** */
		class OutException : std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\033[0;31mThis element didn't exist\033[0m");
				}
		};//!OutException

};//!Array

#endif